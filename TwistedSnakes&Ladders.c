#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

    int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;

    void FillTiles(int[][10]);
    void PrintBoard(int[][10]);
    void GameLoop(int[][10]);
    int turn(int);
    int DiceRoll();

    int main(){
        int tile[10][10];     // Initializing variables 
        FillTiles(tile);
        PrintBoard(tile);
        GameLoop(tile);
        return 0;
    }

    void FillTiles(int tile[][10]){
        int RowCount = 0, ColCount = 0, change = 1;
        for(int i = 100; i>=1; i--){                  // Setting for loop to iterate i from 1 to 100
            tile[RowCount][ColCount] = i;             // Sets the values for individual 2d array element to equal i
            ColCount += change;
            if(ColCount == 10){                            // Checks if it is in the 11th tile
                RowCount++;                           // Moves on to the next row
                ColCount = 9;
                change = -1;
            }
            if(ColCount == -1){
                change = 1;
                ColCount = 0;
                RowCount++; 
            }
        }
    }
    void PrintBoard(int tile[][10]){
        printf("\n\n");
        for(int i = 0; i<=9; i++){
            for(int j = 0; j<=9; j++){
                if(tile[i][j] == pos1){
                    printf("P1  ");
                }
                else if(tile[i][j] == pos2){
                    printf("P2  ");
                }
                else if(tile[i][j] == pos3){
                    printf("P3  ");
                }
                else if(tile[i][j] == pos4){
                    printf("P4  ");
                }
                else {
                    printf("%-3d ", tile[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    void GameLoop(int tile[][10]){
        int win = 0;
        while(!win){
            printf("Player 1's turn\n"); 
            pos1 = turn(pos1);
            PrintBoard(tile);
            printf("Player 2's turn\n");
            pos2 = turn(pos2);
            PrintBoard(tile);
            printf("Player 3's turn\n"); 
            pos3 = turn(pos3);
            PrintBoard(tile);
            printf("Player 4's turn\n"); 
            pos4 = turn(pos4);
            PrintBoard(tile);
            if(pos1 == 100){
                printf("\nPlayer 1 wins!\n");
                win = 1;
            }
            if(pos2 == 100){
                printf("\nPlayer 2 wins!\n");
                win = 1;
            }
            if(pos3 == 100){
                printf("\nPlayer 3 wins!\n");
                win = 1;
            }
            if(pos4 == 100){
                printf("\nPlayer 4 wins!\n");
                win = 1;
            }
        }
    }

    int turn(int pos){
        int roll;
        printf("\nPress enter to roll the dice: ");
            getchar();
            roll = DiceRoll();
            pos += roll;
            if(pos > 100){
                pos = 100-(pos%100);
            }
        return pos;
    }

    int DiceRoll(){
        int dice;
        srand(time(NULL));
        for (int i = 0; i < 20; i++) {  
            dice = (rand() % 6) + 1;
            printf("\r%i", dice);  
            usleep(45000);
        }
        return dice;
    }

    