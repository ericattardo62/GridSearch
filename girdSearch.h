/*
 * searcher.h
 *
 *  Created on: Apr. 26, 2022
 *      Author: ericc
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int winCounter = 0;

void easyGrid();
void mediumGrid();
void hardGrid();
void customGrid();
void difficultySelect();
bool checkWin(int x, int y, int userX, int userY);
void printGrid(int gridX, int gridY, int x, int y);
int inputValidX();
int inputValidY();
void playAgain();
void setTimeout(int milliseconds);