#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic32mx.h>
#include "declarations.h"

//* ----- Code below is written by Abdi & Bran -----

int apple_xpos[] = {44, 72, 107, 12, 83, 56, 92, 7, 35, 98, 22, 114, 59, 103, 6, 42, 78, 18, 66, 15, 76, 50, 9, 101, 30, 64, 119, 55, 121, 39, 89, 27, 73, 109, 14, 87, 46, 105, 33, 70, 10, 118, 60, 97, 24, 68, 38, 84, 53, 111, 16, 81, 48, 116, 3, 123, 21, 62, 115, 49, 104, 74, 11, 57, 95, 29, 67, 36, 122, 20, 91, 41, 77, 52, 108, 26, 63, 117, 8, 94, 31, 69, 45, 106, 19, 80, 54, 113, 28, 58, 99, 23, 75, 43, 102, 32, 110, 61, 5, 79, 47, 112, 25, 86, 34, 100, 17, 93, 51, 63};

int apple_ypos[] = {27, 11, 14, 7, 5, 23, 13, 28, 9, 20, 26, 24, 18, 4, 16, 19, 15, 6, 25, 10, 3, 8, 21, 22, 17, 29, 12, 8, 19, 9, 14, 7, 11, 24, 26, 10, 28, 15, 25, 5, 27, 18, 13, 4, 16, 21, 3, 23, 12, 22, 17, 20, 6, 16, 26, 4, 19, 10, 14, 21, 27, 5, 25, 7, 18, 11, 24, 8, 29, 15, 13, 9, 20, 12, 23, 3, 22, 17, 28, 6, 19, 21, 14, 9, 5, 16, 8, 13, 11, 26, 27, 7, 25, 10, 15, 18, 4, 23};

void spawn_apple(){ // Function to spawn the apple
  int apple_x = apple_xpos[score];
  int apple_y = apple_ypos[score];
  int i, j;

  for (i = 0; i < 2; i++){
    for (j = 0; j < 2; j++){
      human_display[apple_y+i][apple_x+j] = 1;
    }
  }
}

int found_apple(){  // Function to check if the snake has found the apple
  int i, j;
  for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
      if(snake.x[0] == apple_xpos[score] + i && snake.y[0] == apple_ypos[score] + j){
        return 1;
      }
    }
  }
  return 0;
}

void eat(){ // Function to eat the apple
  if(found_apple()){
    snake.length += 4;
    score++;
  }
}
