#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic32mx.h>
#include "declarations.h"

//* ----- Code below is written by Abdi & Bran -----

int hit_wall(){ // Function to check if the snake hits the wall
  if(snake.x[0] < 0 || snake.x[0] > 127 || snake.y[0] < 1 || snake.y[0] > 31){ // If the snake hits the wall
    return 1; // Return 1
  }
  else{
    return 0; // Return 0
  }
}

int hit_self(){ // Function to check if the snake hits itself
  int i;
  for(i = 1; i < snake.length; i++){ // For every part of the snake
    if(snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i]){ // If the snake hits itself
      return 1; // Return 1
    }
  }
  return 0; // Return 0
}
