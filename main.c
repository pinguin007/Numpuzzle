#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void) {
  
  srand(time(NULL));//random time value used to randomize board
  
  
  while(1){
    int rows,cols;

    while(rows<3||cols<3|| rows>8|| cols>8){//repeats until the player enters rows and columns between 3-8
      printf("please enter the number of rows: \n");
      scanf("%d", &rows);

      printf("please enter the number of columns: \n");
      scanf("%d", &cols);
    }
    
    int size= rows*cols;//the overall size of the board

    int gameBoard[size]; //intializing the gameBoard with all zeros
		for (int i = 0; i < size; i++) {
			gameBoard[i] = 0;
		}
    
    // randomizing the location of the numbers  except the last spot. that's already a zero
    int j=0;
    while(j < (size-1)){
          int flag=0;
          int random= 1 + rand() % (size - 1);
          
          for(int i=0; i < size; i++){
            if(gameBoard[i]==random){
              flag=1;
            }
          }

          if(flag==0){
            gameBoard[j]=random;
            j++;
          }
          
    }

    time_t start, end;		// Record the time taken in each round of play
		time(&start);
    int moveCounter=0;  //counts the number of moves

    int playerEntry=1;

    //main game loop. only broken when the player enters 0, or wins by putting the random table in order
    while(playerEntry != 0){ 

        system("clear"); //clear the screen to reprint the table with new moves

        int count=0;
        char emptystring[0];
        emptystring[0]='\0';

        /*This for loop prints the array to the screen in a table fashion(rows, columns)
        When the number of printed cells is perfectly divisable by the number of specified columns, we create a new row
        It also prints an empty cell if it finds a zero 0*/

        for(int i=0; i < size; i++){
          
          if(count==0 || count % cols == 0){

            if(gameBoard[i]==0){
              printf("\n| %2s |", emptystring);
            }
            else{
              printf("\n| %2d |", gameBoard[i]);
            }    
          }

          else{

            if(gameBoard[i]==0){
              printf("| %2s |", emptystring);
            }
            else{
              printf("| %2d |", gameBoard[i]);
            }  
          } 

          count++;
      }

      printf("\n(Move #%d)Enter the number you want to move(press '0' to exit):",moveCounter);
      scanf("%d",&playerEntry);
      
      int num_location;//we find the cell in the array that contains the player's Entry

      for(int i=0; i < size; i++){
        if(gameBoard[i] == playerEntry){
          num_location= i;
        }   
      }

      int zero_location; //we find the cell in the array that contains the zero

      for(int i=0; i < size; i++){
        if(gameBoard[i] == 0){
          zero_location=i;
        }

      }

      /*main game logic that checks the cells to the right of, the left of, above and below the empty cell.
      If playerEntry is one of those cells, the playerEntry will be moved to the location of the empty cell.
      The old location of the playerEntry becomes the new empty cell*/
      int right = zero_location + 1;
      int left = zero_location - 1;
      int down = zero_location + cols;
      int up = zero_location - cols;

      if(right == num_location || left == num_location || down == num_location || up == num_location){
        if ((zero_location+1) % cols == 0 && num_location == right){
          printf("\nNumber cannot be moved");
        }
        else if(zero_location % cols == 0 && num_location == left){
          printf("\nNumber cannot be moved");
        }
        else{
          gameBoard[zero_location] = gameBoard[num_location];
          gameBoard[num_location]=0;
          
          moveCounter++;
        }
      }
      else{
        printf("\nNumber cannot be moved");
      }

      //cheat to solve the gameBoard
      if(playerEntry==75949){
        for(int i=1; i < size; i++){
          gameBoard[i-1]=i;
        }
      }
      
      //checks if the board is organized by counting from the beginning and checking if the next number is greater by a factor of 1.
      while(1){
        int counter1=0;
        for(int i=0; i<size;i++){
          if (gameBoard[i]==counter1+1){
            counter1++;
          }
        }
        if (counter1==size-1){
            double t = difftime(end,start);
						printf("\nExcellent!!! you solved it with %d guesses, in %3.0f seconds.\n",moveCounter, t); 
            playerEntry=0;
        }
        break;
      }

    }

    printf("\ndo you want to keep playing. Yes(1), No(0): \n");

    int keepPlaying; // exit the game if the player enters 0. loop to start new game if 1 is entered.

    scanf("%d", &keepPlaying);

    if(keepPlaying == 0){break;}
  }
  
  printf("GoodBye!\n");

	return 0;
}


