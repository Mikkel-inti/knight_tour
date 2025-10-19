/**
 * @file knights_tour.c
 * @brief Implementation of the Knight’s Tour (Greedy) algorithm.
 *
 * Course: 62712 - Basic C Programming (DTU)
 * Author: Mikkel Olsen
 * Date: October 2025
 */

#include "knights_tour.h"
#include <stdio.h>

static const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
static const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {
  int check_x = (int)x + MOVES_X[move_id];
  int check_y = (int)y + MOVES_Y[move_id];

  // Checking board bounds
  if (check_x < 0 || check_x >= (int)SIZE)
    return false;
  if (check_y < 0 || check_y >= (int)SIZE)
    return false;

  // Already visited?
  if (visited[(size_t)check_y][(size_t)check_x] != 0)
    return false;

  return true;
}

unsigned int tour_greedy(size_t x, size_t y) {

  // Init variables:

  board_t board = {0};   // Init board with zeros
  unsigned int step = 1; // Numbers of steps
  board[y][x] = step;

  while (1) {
    bool moved = false;
    for (size_t move = 0; move < MOVE_COUNT; ++move) {

      // Checking if the move is possible
      bool move_possible = move_is_possible(move, x, y, board);

      if (move_possible == true) {
        x += MOVES_X[move];
        y += MOVES_Y[move];

        board[y][x] = ++step; // Enumerate the step at position 'y' and 'x'
        moved = true;
        break; //
      }
    }

    if (!moved) // If the knight did/could not move.
      break;    // The tour is done.
  }
  return step; // Returning the steps taken in the tour.
}

void greedy_tour_from_each_square(void) {
  puts("Greedy:");
  // Loops: Setting the starting position for the knight
  // for each tour.
  for (size_t start_y = 0; start_y < SIZE; ++start_y) {
    for (size_t start_x = 0; start_x < SIZE; ++start_x) {

      unsigned int visited_count = tour_greedy(start_x, start_y);

      // Printing the final board
      if (start_x + 1 == SIZE) {
        printf("%2u\n",
               visited_count); // If the last element in the col, print: count
                               // and then newline
      } else {
        printf("%2u ", visited_count); // Printing count
      }
    }
  }
}
