/**
 * @file main.c
 * @brief Entry point for the Knight’s Tour (Greedy) program.
 *
 * Created for DTU course: 62712 - Basic C Programming (Week 06)
 * Author: Mikkel Olsen
 * Date: October 2025
 */

#include "knights_tour.h"

int main(void) {
  greedy_tour_from_each_square(); // Running knights tour with the defualt board
                                  // size 8x8
  return 0;
}
