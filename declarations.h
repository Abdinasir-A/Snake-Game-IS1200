#include <stdint.h>   /* Declarations of uint_32 and the like */

/* Declare bitmap array containing font, icon, and fish */
extern const uint8_t const font[128*8];
extern const uint8_t const icon[128];

/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Declare lab-related functions */
char * itoaconv( int num );
void labwork(void);
int nextprime( int inval );
void quicksleep(int cyc);
void tick( unsigned int * timep );

/* Declare display-related functions */
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_string_and_char(int line, char *s, char *c); //! UNUSED
void display_string_and_int(int line, char *s, int num);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare functions written by students. */
void delay(int); //! UNUSED
void time2string( char *, int ); //! UNUSED
int getbtns(void);

/* Declare debugging function */
void display_debug( volatile int * const addr );


//? ----- The code above was given from previous labs -----
//* ----- Code below is written by Abdi & Bran -----

typedef struct Snake{ // Struct to represent the snake
  uint8_t *x;  
  uint8_t *y;  
  int length;  
  uint8_t direction; 
} Snake;

Snake snake;  // Declare the snake

/* Declare game data */
uint8_t human_display[32][128];
uint8_t computer_display[512];
uint8_t snake_xpos[200];
uint8_t snake_ypos[200];
int score;
int high_score;

/* Declare game functions */
void gameover();
void game_init();
void show_snake();
void change_direction();
void eat();
void move_snake();
void spawn_apple();
void snake_init();
int found_apple();
int hit_wall();
int hit_self();
void game();
void menu();