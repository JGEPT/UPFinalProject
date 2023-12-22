/*
=====================================================================================================================================================
FILE		: TwistedSnakes&Ladders
AUTHORS		: Hyacinth Marie B. Kanazawa, James Gabriel Elijah P. Ty, Aira Gayle D. Uy
DESCRIPTION	: A C program of a twisted version of snakes and ladders where the snakes and ladders change position each time
DATE	    : 12/22/23
=====================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

    int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
    int TopRow1 = -1, TopColumn1 = -1, head1 = -1, tail1 = -1;
    int TopRow2 = -1, TopColumn2 = -1, head2 = -1, tail2 = -1;
    int TopRow3 = -1, TopColumn3 = -1, head3 = -1, tail3 = -1;
    int TopRow4 = -1, TopColumn4 = -1, up1 = -1, down1 = -1; 
    int TopRow5 = -1, TopColumn5 = -1, up2 = -1, down2 = -1; 
    int TopRow6 = -1, TopColumn6 = -1, up3 = -1, down3 = -1; 

    // List of Function Prototypes
    void FillTiles(int[][10]);                    
    int SelectPlayers();                          
    void SnakesLadders(int[][10]);
    void PrintBoard(int[][10]);
    int WithinBoard(int, int, int, int);
    int ValidMove(int, int, int, int, int[][10]);
    void SnakesLadders(int[][10]);
    void red();
    void yellow();
    void blue();
    void green();
    void purple();
    void brown();
    void resetColor();
    void GameLoop(int[][10], int);
    int turn(int);
    int DiceRoll();

    int main(){
        int tile[10][10];                     
        int NumPlayers = SelectPlayers();
        FillTiles(tile);                      
        GameLoop(tile, NumPlayers);
        return 0;
    }

/*
=========================================================================================================================
FUNCTION	: FillTiles void function
DESCRIPTION	: This function sets a number for each tile in the board, going from 1 to 100
ARGUMENTS	: None
RETURNS		: None
=========================================================================================================================
*/
    void FillTiles(int tile[][10]){
        int RowCount = 0, ColCount = 0, change = 1;
        for(int i = 100; i>=1; i--){                  // Setting for loop to iterate i from 1 to 100
            tile[RowCount][ColCount] = i;             // Sets the values for individual 2d array element to equal i
            ColCount += change;
            if(ColCount == 10){                       // Checks if column goes past the 10th tile
                RowCount++;                           // Moves on to the next row
                ColCount = 9;                         // Set column count to 9, to start from the right end of the row
                change = -1;                          // Sets the value of tiles from right to left in the row
            }
            if(ColCount == -1){                       // Checks if column goes past the 1st tile in the row
                change = 1;                           // Sets the value of tiles from left to right in the row
                ColCount = 0;                         // Sets column count to 0, to start from the left end of the row
                RowCount++;                           // Moves on to the next row
            }
        }
    }

/*
=========================================================================================================================
FUNCTION	: SelectPlayers int function
DESCRIPTION	: This function lets the user select number of players from 2 to 4
ARGUMENTS	: None
RETURNS		: NumPlayers
=========================================================================================================================
*/
    int SelectPlayers(){
        int NumPlayers;                                                    // Initialize variables
        printf("Enter number of players (2-4): ");                         // Prompt
        scanf("%d", &NumPlayers);                                          // Get user input
        while (NumPlayers > 4 || NumPlayers < 2){                          // Check for error in input
            printf("Invalid input, please enter a number from 2-4.\n");
            printf("Enter number of players (2-4): ");
            scanf("%d", &NumPlayers);
        }
        return NumPlayers;                                                // Return number of players
    }

/*
=========================================================================================================================
FUNCTION	: SnakesLadders void function
DESCRIPTION	: This function sets the snakes and ladders in the board
ARGUMENTS	: int tile[][10]
RETURNS		: None
=========================================================================================================================
*/
    void SnakesLadders(int tile[][10]){
        // First top and tail
        do {
            TopRow1 = rand() % 9;                         // Sets random value for the row of snake's head from 0 to 9 (limit of board)
            TopColumn1 = rand() % 9;                      // Sets random value for the column of snake's head from 0 to 9 (limit of board)
            head1 = tile[TopRow1][TopColumn1];            // Sets the final position of snake's head in the board
            tail1 = tile[TopRow1 + 3][TopColumn1 - 2];    // Sets the final position of snake's tail in the board based from the head
        } while ((!WithinBoard(TopRow1, TopColumn1, 3, 2) ||                              // Checks if the snake is within the board's dimensions
             (head1 == head2 || head1 == tail2 || tail1 == head2 || tail1 == tail2) ||    // The following lines check if snake's head and tail do not touch any other obstacle
             (head1 == head3 || head1 == tail3 || tail1 == head3 || tail1 == tail3) ||
             (head1 == up1 || head1 == down1 || tail1 == up1 || tail1 == down1) || 
             (head1 == up2 || head1 == down2 || tail1 == up2 || tail1 == down2) || 
             (head1 == up3 || head1 == down3 || tail1 == up3 || tail1 == down3)); 

        // Second top and tail
        do {
            TopRow2 = rand() % 9;
            TopColumn2 = rand() % 9;
            head2 = tile[TopRow2][TopColumn2];
            tail2 = tile[TopRow2 + 6][TopColumn2 - 5];
        } while ((!WithinBoard(TopRow2, TopColumn2, 6, 5) ||
             (head2 == head1 || head2 == tail1 || tail2 == head1 || tail2 == tail1) ||
             (head2 == head3 || head2 == tail3 || tail2 == head3 || tail2 == tail3) ||
             (head2 == up1 || head2 == down1 || tail2 == up1 || tail2 == down1) || 
             (head2 == up2 || head2 == down2 || tail2 == up2 || tail2 == down2) || 
             (head2 == up3 || head2 == down3 || tail2 == up3 || tail2 == down3));

        // Third top and tail
        do {
            TopRow3 = rand() % 9;
            TopColumn3 = rand() % 9;
            head3 = tile[TopRow3][TopColumn3];
            tail3 = tile[TopRow3 + 4][TopColumn3 - 1];
        } while ((!WithinBoard(TopRow3, TopColumn3, 4, 2) ||
             (head3 == head1 || head3 == tail1 || tail3 == head1 || tail3 == tail1) ||
             (head3 == head2 || head3 == tail2 || tail3 == head2 || tail3 == tail2) ||
             (head3 == up1 || head3 == down1 || tail3 == up1 || tail3 == down1) || 
             (head3 == up2 || head3 == down2 || tail3 == up2 || tail3 == down2) || 
             (head3 == up3 || head3 == down3 || tail3 == up3 || tail3 == down3)); 

        // First ladder
        do {
            TopRow4 = rand() % 9;                       // Sets a random value for the row of the top of the ladder from 0 to 9 (limit of board)
            TopColumn4 = rand() % 9;                    // Sets a random value for the column of the top of the ladder from 0 to 9 (limit of board)
            up1 = tile[TopRow4][TopColumn4];            // Sets final position of the top of the ladder in the board
            down1 = tile[TopRow4 + 2][TopColumn4 - 8];  // Sets final position of the bottom of the ladder based from the top
        } while ((!WithinBoard(TopRow4, TopColumn4, 2, 8) ||                        // Checks if ladder is within the board's dimensions
             (up1 == head1 || up1 == tail1 || down1 == head1 || down1 == tail1) ||  // Checks if ladder's top and bottom do not touch any other obstacle
             (up1 == head2 || up1 == tail2 || down1 == head2 || down1 == tail2) ||
             (up1 == head3 || up1 == tail3 || down1 == head3 || down1 == tail3) ||
             (up1 == up2 || up1 == down2 || down1 == up2 || down1 == down2) ||  
             (up1 == up3 || up1 == down3 || down1 == up3 || down1 == down3));  

        // Second ladder
        do {
            TopRow5 = rand() % 9;
            TopColumn5 = rand() % 9;
            up2 = tile[TopRow5][TopColumn5];      
            down2 = tile[TopRow5 + 7][TopColumn5 - 2];  
        } while ((!WithinBoard(TopRow5, TopColumn5, 7, 2) ||
             (up2 == head1 || up2 == tail1 || down2 == head1 || down2 == tail1) ||
             (up2 == head2 || up2 == tail2 || down2 == head2 || down2 == tail2) ||
             (up2 == head3 || up2 == tail3 || down2 == head3 || down2 == tail3) ||
             (up2 == up1 || up2 == down1 || down2 == up1 || down2 == down1) ||  
             (up2 == up3 || up2 == down3 || down2 == up3 || down2 == down3));   

        // Third ladder
        do {
            TopRow6 = rand() % 9;
            TopColumn6 = rand() % 9;
            up3 = tile[TopRow6][TopColumn6];    
            down3 = tile[TopRow6 + 5][TopColumn6 - 6];  
        } while ((!WithinBoard(TopRow6, TopColumn6, 5, 6) ||
             (up3 == head1 || up3 == tail1 || down3 == head1 || down3 == tail1) ||
             (up3 == head2 || up3 == tail2 || down3 == head2 || down3 == tail2) ||
             (up3 == head3 || up3 == tail3 || down3 == head3 || down3 == tail3) ||
             (up3 == up1 || up3 == down1 || down3 == up1 || down3 == down1) ||  
             (up3 == up2 || up3 == down2 || down3 == up2 || down3 == down2));
    }
/*
=========================================================================================================================
FUNCTION	: PrintBoard void function
DESCRIPTION	: This function prints the board with the numbers, snakes, and ladders
ARGUMENTS	: int tile[][10]
RETURNS		: None
=========================================================================================================================
*/
    void PrintBoard(int tile[][10]){
        printf("\n\n");                        // Print spaces
        for(int i = 0; i<=9; i++){              // L
            for(int j = 0; j<=9; j++){
                if(tile[i][j] == pos1){
                    brown();
                    printf("P1  ");
                    resetColor();
                }
                else if(tile[i][j] == pos2){
                    blue();
                    printf("P2  ");
                    resetColor();
                }
                else if(tile[i][j] == pos3){
                    purple();
                    printf("P3  ");
                    resetColor();
                }
                else if(tile[i][j] == pos4){
                    green();
                    printf("P4  ");
                    resetColor();
                }
                else if (tile[i][j] == head1) {
                red();
                printf("S1  ");
                resetColor();
            } else if (tile[i][j] == head2) {
                red();
                printf("S2  ");
                resetColor();
            } else if (tile[i][j] == head3) {
                red();
                printf("S3  ");
                resetColor();
            } else if (tile[i][j] == tail1) {
                red();
                printf("s1  ");
                resetColor();
            } else if (tile[i][j] == tail2) {
                red();
                printf("s2  ");
                resetColor();
            } else if (tile[i][j] == tail3) {
                red();
                printf("s3  ");
                resetColor();
            } else if (tile[i][j] == up1) { 
                yellow();
                printf("L1  ");
                resetColor();
            } else if (tile[i][j] == up2) { 
                yellow();
                printf("L2  ");
                resetColor();
            } else if (tile[i][j] == up3) { 
                yellow();
                printf("L3  ");
                resetColor();
            } else if (tile[i][j] == down1) { 
                yellow();
                printf("l1  ");
                resetColor();
            } else if (tile[i][j] == down2) { 
                yellow();
                printf("l2  ");
                resetColor();
            } else if (tile[i][j] == down3) { 
                yellow();
                printf("l3  ");
                resetColor();
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

/*
=========================================================================================================================
FUNCTION	: WithinBoard int function
DESCRIPTION	: This function checks if the snake or ladder is within the board's dimensions
ARGUMENTS	: int TopRow, int TopColumn, int move1, int move2
RETURNS		: 0 or 1
=========================================================================================================================
*/
    int WithinBoard(int TopRow, int TopColumn, int move1, int move2) {
        return (TopRow + move1 >= 0) && (TopRow + move1 <= 9) && (TopColumn + move2 >= 0) && (TopColumn + move2 <= 9);    // Checks if the snake's tail or the ladder's bottom part does not go out of the board
    }

    void red() {
        printf("\033[1;31m");
    }

    void yellow() {
        printf("\033[1;33m");
    }

    void green() {
        printf("\033[1;32m");
    }

    void blue() {
        printf("\033[1;34m");
    }
    void purple() {
        printf("\033[1;35m");
    }

    void brown() {
        printf("\033[1;38;2;150;75;0m");
    }

    void resetColor() {
        printf("\033[0m");
    }

    void GameLoop(int tile[][10], int NumPlayers){
        int win = 0;
        while(!win){
            SnakesLadders(tile);
            PrintBoard(tile);
            printf("Player 1's turn\n"); 
            pos1 = turn(pos1);
            PrintBoard(tile);
            printf("Player 2's turn\n");
            pos2 = turn(pos2);
            if(NumPlayers >= 3){
                PrintBoard(tile);
                printf("Player 3's turn\n"); 
                pos3 = turn(pos3);
                if(NumPlayers == 4){
                    PrintBoard(tile);
                    printf("Player 4's turn\n"); 
                    pos4 = turn(pos4);
                }  
            }
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
            fflush(stdin);
            getchar();
            roll = DiceRoll();
            pos += roll;
            if (pos == head1){
                pos = tail1;
            }
            if (pos == head2){
                pos = tail2;
            }
            if (pos == head3){
                pos = tail3;
            }
            if (pos == down1){
                pos = up1;
            }
            if (pos == down2){
                pos = up2;
            }
            if (pos == down3){
                pos = up3;
            }
            if(pos > 100){
                pos = 100-(pos%100);
            }
        return pos;
    }

/*
=========================================================================================================================
FUNCTION	: DiceRoll int function
DESCRIPTION	: This function rolls the die, getting a value from 1 to 6
ARGUMENTS	: None
RETURNS		: dice
=========================================================================================================================
*/
    int DiceRoll(){
        int dice;                        // Initializing variable
        srand(time(NULL));               // Seeds the generator
        for (int i = 0; i < 20; i++) {   // This loop displays animation of the die rolling
            dice = (rand() % 6) + 1;     // Die gets a random value from 1 to 6
            printf("\r%d", dice);        // Outputs the die
            usleep(45000);               // Adds a delay that allows to adjust speed of die rolling
        }
        return dice;                    // Returns final die value
    }

    
