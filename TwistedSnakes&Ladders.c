#include <stdio.h>

    int main(){
        int tile[10][10], RowCount = 0, ColCount = 0, change = 1, i, j;     // Initializing variables 
        for(i = 100; i>=1; i--){                  // Setting for loop to iterate i from 1 to 100
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
        for(i = 0; i<=9; i++){
            for(j = 0; j<=9; j++){
                printf("%d ", tile[i][j]);
            }
            printf("\n");
        }
        return 0;
    }