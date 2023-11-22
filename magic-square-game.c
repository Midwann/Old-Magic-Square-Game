#include <stdio.h>
#include <stdbool.h>

// where the board is displayed

void Squareboard(int board[3][3]) {
  int Row, Column;

     printf("  +---+---+---+\n");
  
  for (Row = 0; Row < 3; Row++) //where it amounts the column
{
    printf("%d |", Row + 1);
    for (Column = 0; Column < 3; Column++) //where it amounts the column
    {
        int Value = Row;
        printf(" %d |", board[Value][Column]); 
    }
    printf("\n");
    printf("  +---+---+---+\n");
}
    
    printf("    1   2   3\n");
}

// Checks if winning conditions are met
int GameOverW(int board[3][3], int Turn) {
  int Row, Column;
  int Sum = 0;
  int Winner = 0;
  int Numbers = 0;

  // Check rows
  for (Row = 0; Row < 3; Row++) {
    Sum = 0;
    for (Column = 0; Column < 3; Column++) {
      Sum += board[Row][Column];
      if (board[Row][Column] != 0)
        Numbers++;
    }
    if (Sum == 15 && Numbers == 3) // if 3 added numbers are equal to 15, then winner.
    {
      Winner++;
    } else if (Sum < 15 && Numbers == 3) // lose if the results are opposite.
    
    {
      printf("\n======================\n\nPlayer %d has lost!\n", Turn % 2);
      Squareboard(board);
    }
    Numbers = 0;
    Sum = 0;
  }

  // Check columns
  for (Column = 0; Column < 3; Column++) {
    Sum = 0;
    for (Row = 0; Row < 3; Row++) {
      Sum += board[Row][Column];
      if (board[Row][Column] != 0)
        Numbers++;
    }
    if (Sum == 15 && Numbers == 3) // if 3 added numbers are equal to 15, then winner.
    {
      Winner++;
    } else if (Sum < 15 && Numbers == 3) // lose if the results are opposite.
    {
      printf("\n======================\n\nPlayer %d has lost!\n", Turn % 2);
      Squareboard(board);
    }
    Numbers = 0;
    Sum = 0;
  }

  return Winner; //it will treat the Winner variable as an end to the game.
}
// End of checking winning condition

// the skeleton of the board where int board [3][3] is the arrays of every position
int main(){
  
  int board[3][3] = {{0, 0, 0}, 
                     {0, 0, 0}, 
                     {0, 0, 0}};
  int xCord, yCord, Digit, a, b; 
  int Win = 0;
  int Turn = 0; //will be called on a different function like GameOverW
  int State = 0;
  bool done = false;

  // Start of main menu
  int nMenu;
  
	do{
		printf("[1] Start\n");
		printf("[2] Quit\n");
		printf("What will you do?: ");
		scanf("%d", &nMenu);
		
			switch(nMenu){
				case 1:
					printf("Starting Game...\n");
					break;
				case 2:
					printf("Quitting Games...");
          return 0;
					break;
			}
			printf("\n");
	} 
    
	while (nMenu != 1);

 // End of main menu

    while (!done) {
      printf("\n======================\n\n     Player %d\n", (Turn % 2) + 1);
      
      Squareboard(board); // Displays Squareboard
      
     
    printf("Insert Horizontal Coordinate number from 1-3 (-): ");
    scanf("%d", &xCord); // Gives direction to x axis number
    printf("Insert Vertical Coordinate number from 1-3 (|): ");
    scanf("%d", &yCord); // Gives direction to y axis number

    if(board[xCord - 1][yCord - 1] == 0 
    // checks if the position on the board corresponding to the inputted coordinate is empty (has a value of 0).
                                        && xCord < 4 && xCord > 0 
                                      // horizontal coord is within the range of 1-3
                                      
                                        && yCord < 4 && yCord > 0)
                                      // vertical coord is within the range of 1-3
    {
    printf("Enter a number (1-9): ");
    scanf("%d", &Digit);

      // nested for loop, note that a and b are like x and y coordinates.
    State = 0;
    for(a = 0;a < 3; a++)
        for(b = 0;b < 3;b++)
            if(board[a][b] == Digit)
                State++; /*ensures that the coordinate given is correct and will be
                                                                        inputted. */

    if(Digit < 10 && Digit > 0 && State == 0) 
      {
        board[xCord - 1][yCord - 1] = Digit;
        Turn++; // Gives a fixed position in inputting a number in the magic square board
        
        
      }   
      else
        printf("\n The number you entered is incorrect. Try again.\n");
    }
      else 
        printf("\n The coordinate you entered is incorrect. Try again.\n");

      
      // The winning condition
      Win = GameOverW(board, Turn);
      if (Win > 0) {
    printf("\n======================\n\nPlayer %d is the winner!\n", (Turn % 2));
    Squareboard(board);
    done = true;

  Turn++; 

      
}
}
}

/* Rules */

// The game is a 3x3 magic square based. Meaning all of the rows and columns in numbers ranging 1-9 must be equal to 15. That means if the first row is 9 + 4 + 2 = 15, it is correct.

// 15 15  15  15  15
// 15 |2| |7| |6| 15
// 15 |9| |5| |1| 15
// 15 |4| |3| |8| 15
// 15 15  15  15  15

//The game only has two players and is given 1 turn in intervals. Whoever manages to do a correct magic square aka three numbers equal to 15 (whether it is in row and column) wins the game.

// Should the 3x3 board be filled with numbers that is not equal to 15, the game will result in a tie.

// ex: Player A's turn, then Player B's turn. on deciding if they add a number in vertical or horizontal positions.
