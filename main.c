#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "declarations.h"  /* Declarations for these labs */
# define TM2PERIOD ((80000000/256)/10)

#if TM2PERIOD > 0xffffffff // Får inte vara större än  32-bit value
#error "Timer period is too big."
#endif
//* ----- Code below is written by Abdi & Bran ----- 

enum Game_State {START_GAME, GAME_OVER, HOME_SCREEN};	// Declare the game states

int BUTTONS;
int getbtns(){
  BUTTONS = (PORTD >> 5) & 0x07;                                // Mask buttons 2-4
  BUTTONS = (BUTTONS << 1 );                                    // Shift one step to the left
  BUTTONS = BUTTONS | ((PORTF >> 1) & 0x01);                    // "add" result from btn1 (stored in RF1)
  return BUTTONS;
}


void labinit(void){
T2CONSET = 0x70; // 0111 0000 för 1:256 prescaling.
                 // ON-bit (bit 15) also gets set to

PR2 = TM2PERIOD; // Bestämd timeperioden

TMR2 = 0;        // Startar om timern. Will ensure that the timer
                 // Starts at a well-defined value, when we start it

T2CONSET = 0x8000;//Vi sätter ON-bit ( bit 15), till 1 för att starta timern

// Enabling interruption

// Interrupt enable controll register. bit 8 = T2IE
IECSET(0) = 0x100;

// Interrupt priority control, should both be highest
// Setting priority 7 and sub-priority 3.
// bit 4-2: 0111 = 7 (T2IP)
// bit 1-0: 11 = 3 (T2IS)
// IPC2: 000111 11 = 0x1F
IPCSET(2) = 0x1f;

}

int main(void) {	// Main function
    setup();

    enum Game_State game_state = HOME_SCREEN;	// Set the game state to home screen

    display_init();	// Initialize the display
    snake_init();	// Initialize the snake
    labinit();

    while( 1 )	// While loop to check the game state
    {
        switch (game_state)
        {
        case HOME_SCREEN :
            menu();
            game_state = START_GAME;
            break;

        case START_GAME :
            game();
            if (hit_wall() || hit_self())
                game_state = GAME_OVER;
            break;
        
        case GAME_OVER:
            gameover();
            game_state = START_GAME;
            break;
        }
    }
    return 0;
}