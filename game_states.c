#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic32mx.h>
#include "declarations.h"

//* ----- Code below is written by Abdi & Bran -----

int user_wants_to_start_game(){ // Function to check if the user wants to start the game
  int btn = getbtns();  // Get the buttons
  if(btn == 1){ 
    return 1;
  }
  return 0; 
}

void menu(){  // Function to display the menu
  clear_display();  // Clear the display
  display_string(0, "SNAKE GAME");
  display_string(1, "by Bran & Abdi");
  display_string(2, ""); 
  display_string(3, "press 1 to go"); 
  map(); // Map the display
  display_image(0, computer_display);
  while(1){
    display_update(); // Update the display
    if(user_wants_to_start_game()){
      snake_init();  // Initialize the snake
      break;
    }
  }
}

void game(){  // Function to play the game
  clear_display();
  game_init();
  labinit();
  map();
  display_image(0, computer_display);
}

void gameover(){  // Function to display game over
  if(score > high_score){ // If the score is higher than the highscore, set the highscore to the current score
    high_score = score;
  }
  clear_display(); 
  display_string(0, "GAME OVER"); 
  display_string_and_int(1, "Score: ", score); 
  display_string_and_int(2, "Highscore: ", high_score); 
  display_string(3, "Press 1 to go!");
  map();  // Map the display
  display_image(0, computer_display);

  while(1){ // While loop to check if the user wants to restart the game
    display_update();  // Update the display
    if(user_wants_to_start_game()){
      snake_init();  // Initialize the snake
      break; 
    }
  }
}