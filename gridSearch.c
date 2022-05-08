/*
 * searcher.c
 *
 *  Created on: Apr. 26, 2022
 *      Author: ericc
 */

#include "search.h"

int main ()
{
  srand(time(NULL));
  printf("Welcome to Searcher!\nThis game works by generating a large grid of uppercase 'X' characters and 1 lowercase 'x' character.\nYou, the user, are tasked with finding the location of this lowercase 'x' and entering the coordinates before time runs out!\nGoodLuck!!!\n---------------------------------------------------------------\n");
  difficultySelect ();
  return 0;
}

void easyGrid(){
    int x, y, userX, userY;
    bool win = false;
    char eGrid[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            eGrid[i][j] = 'X';
        }
    }
    
    x = (rand() % 4);
    y = (rand() % 4);
    eGrid[y][x] = 'x';
    
    printGrid(4, 4, x, y);
    
    while(!win){
        userX = inputValidX();
        userY = inputValidY();
        win = checkWin(x, y, userX, userY);
    }
    
    playAgain();
}


void mediumGrid(){
    int x, y, userX, userY, input;
    char temp;
    bool win = false;
    char eGrid[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            eGrid[i][j] = 'X';
        }
    }
    
    x = (rand() % 8);
    y = (rand() % 8);
    eGrid[y][x] = 'x';
    
    printGrid(8, 8, x, y);
    
    while(!win){
        userX = inputValidX();
        userY = inputValidY();
        win = checkWin(x, y, userX, userY);
    }
    
    playAgain();
}

void largeGrid(){
    int x, y, userX, userY;
    bool win = false;
    char eGrid[16][16];
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            eGrid[i][j] = 'X';
        }
    }
    
    x = (rand() % 16);
    y = (rand() % 16);
    eGrid[y][x] = 'x';
    
    printGrid(16, 16, x, y);
    
    while(!win){
        userX = inputValidX();
        userY = inputValidY();
        win = checkWin(x, y, userX, userY);
    }
    
    playAgain();
}

void customGrid(){
    int sizeX, sizeY;
    
    printf("Enter the X then Y dimension of your grid...\n");
    sizeX = inputValidX();
    sizeY = inputValidY();
    int x, y, userX, userY;
    bool win = false;
    char eGrid[sizeY][sizeX];
    for(int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX; j++){
            eGrid[i][j] = 'X';
        }
    }
    
    x = (rand() % sizeX);
    y = (rand() % sizeY);
    eGrid[y][x] = 'x';
    
    
    printGrid(sizeX, sizeY, x, y);
    
    while(!win){
        userX = inputValidX();
        userY = inputValidY();
        win = checkWin(x, y, userX, userY);
    }
    
    playAgain();
}

void difficultySelect ()
{
  int difficulty, input, temp;
  
    printf("Enter a Number to Choose Difficulty:\n1 - Easy (4x4) --- 2 - Medium (8x8) --- 3 - Hard (16x16) --- 4 - Custom Size --- 5 - Exit\nEnter Difficulty: ");
    input = scanf ("%d", &difficulty);
    temp = getchar();
  
    while(input!=1){
        printf("Invalid Entry, Enter the Difficulty as an Interger: ");
        input = scanf("%d", &difficulty);
        temp = getchar();
    }

  while (difficulty < 1 || difficulty > 5)
    {
        printf("Invalid Difficulty Entered, try again...\n");
        printf("Enter a Number to Choose Difficulty:\n1 - Easy (4x4) --- 2 - Medium (8x8) --- 3 - Hard (16x16) --- 4 - Custom Size --- 5 - Exit\nEnter Difficulty: ");
        input = scanf("%d", &difficulty);
        temp = getchar();
  
        while(input!=1){
            printf("Invalid Entry, Enter the Difficulty as an Interger: ");
            input = scanf("%d", &difficulty);
            temp = getchar();
        }
    }
    
    switch(difficulty){
        case 1:
            easyGrid();
            break;
            
        case 2:
            mediumGrid();
            break;
            
        case 3:
            largeGrid();
            break;
            
        case 4:
            customGrid();
            break;
        
        case 5:
            printf("Exiting Program...");
            exit(0);
            break;
            
        default:
            printf("Error...");
    }
}

bool checkWin(int x, int y, int userX, int userY){
    if(x + 1 == userX && y + 1 == userY){
        printf("You win!");
        winCounter++;
        return true;
    }
    else{
        printf("Try Again!\n");
        return false;
    }
}

void printGrid(int gridX, int gridY, int x, int y){
  
    printf("       ");
    for(int i = 0; i < gridX; i++){
        if(i < 9){
            printf("%d  ", i + 1);
        }
        else{
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    
    for(int i = 0; i < gridY; i++){
        printf("%2d --- ", i + 1);
        for(int j = 0; j < gridX; j++){
            if(i == y && j == x){
                printf("x  ");
            }
            else{
                printf("X  ");
            }
        }
        printf("\n");
    }
}

int inputValidX(){
    int userX, input, temp;
    printf("Enter the X Value: ");
        input = scanf("%d", &userX);
        temp = getchar();
        while(input!=1){
            printf("Invalid Entry, Enter the X Value as an Interger: ");
            input = scanf("%d", &userX);
            temp = getchar();
        }
    
    return userX;
}

int inputValidY(){
    int userY, input, temp;
    printf("Enter the Y Value: ");
        input = scanf("%d", &userY);
        temp = getchar();
        while(input!=1){
            printf("Invalid Entry, Enter the Y Value as an Interger: ");
            input = scanf("%d", &userY);
            temp = getchar();
        }
    
    return userY;
}

void playAgain(){
    char input, temp;
    printf("\n---------------------------------------------------------------\nCurrent Score: %d\nWould you like to play again?\nEnter Y for Yes or N for No: ", winCounter);
    scanf(" %c", &input);
    temp = getchar();
    
    while(tolower(input) != 'y' && tolower(input) != 'n'){
        printf("Please enter 'Y' or 'N': ");
        scanf(" %c", &input);
        temp = getchar();
    }
    
    if(tolower(input) == 'n'){
        printf("\nThanks for Playing!\n---------------------------------------------------------------");
        exit(0);
    }
    
    else if(tolower(input) == 'y'){
        printf("\nLoading Difficulty Select...\n---------------------------------------------------------------\n");
        difficultySelect();
    }
}












