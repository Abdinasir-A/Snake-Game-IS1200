#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic32mx.h>
#include "declarations.h"

//* ----- Code below is written by Abdi & Bran -----

void show_snake(){  // Function to show the snake
  int i;
  for(i = 0; i < snake.length; i++){ // For every part of the snake
    human_display[snake.y[i]][snake.x[i]] = 1; // Set the part in the array
  }
}

void move_snake(){  // Function to move the snake
  int i;
  for(i = snake.length - 1; i > 0; i--){
    snake.x[i] = snake.x[i-1];  // Move the x-coordinate of the part
    snake.y[i] = snake.y[i-1];  // Move the y-coordinate of the part
  }

  switch(snake.direction){
    case 1: snake.x[0]++; break; // right
    case 2: snake.y[0]++; break; // down
    case 4: snake.y[0]--; break; // up
    case 8: snake.x[0]--; break; // left
  }

  change_direction();
}

void change_direction(){  // Function to change the direction of the snake
  int btns = getbtns();

  if (snake.direction != 8 && btns == 1) snake.direction = 1; // If the snake is not moving left and the user presses right, change direction to right
  if (snake.direction != 4 && btns == 2) snake.direction = 2; // If the snake is not moving up and the user presses down, change direction to down
  if (snake.direction != 2 && btns == 4) snake.direction = 4; // If the snake is not moving down and the user presses up, change direction to up
  if (snake.direction != 1 && btns == 8) snake.direction = 8; // If the snake is not moving right and the user presses left, change direction to left
}

void snake_init(){  // Function to initialize the snake
  snake.x = snake_xpos; // Set the x-coordinate of the snake
  snake.y = snake_ypos; // Set the y-coordinate of the snake
  snake.length = 8;
  snake.direction = 0x1; // Set the direction of the snake to right
  score = 0;  // Set the score to 0, max score is 99

  int i;
  int start_row = 10; // Set the start row
  int head_start_pos_col = 20;  
  for(i = 0; i < snake.length; i++){ // For every part of the snake
    snake.x[i] = head_start_pos_col - i; // Set the x-coordinate of the part
    snake.y[i] = start_row;  // Set the y-coordinate of the part
  }
}

void game_init(){ // Function to initialize the game
  move_snake();
  if(found_apple()) eat();
  show_snake();
  spawn_apple();
  labinit();
}