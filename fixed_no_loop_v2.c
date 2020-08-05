/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void) {
  
  srand(time(NULL));
  
  
  do{
    int rows,cols,size;

    do{
      printf("please enter the number of rows: \n");
      scanf("%d", &rows);

      printf("please enter the number of columns: \n");
      scanf("%d", &cols);
    }while(rows<3||cols<3|| rows>8|| cols>8);
    
    size= rows*cols;

    int gameBoard[size];
		for (int i = 0; i < size; i++) {
			gameBoard[i] = 0;
		}

    int orderedBoard[size];
    for (int i = 0; i < size; i++) {
			orderedBoard[i] = 0;
		}
    
    for(int i=0; i < size; i++){
      orderedBoard[i]=i;
    }

    int j=0;

    do{
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
          
    }while(j < (size-1));


    gameBoard[size-1]=0;
    
    orderedBoard[size-1]=0;

    int playerEntry=1;

    do{       //add a comparison function
      
        int count=0;
        char emptystring[0];
        emptystring[0]='\0';

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

      printf("\nEnter the number you want to move(press '0' to exit): \n");
      scanf("%d",&playerEntry);
      
      int num_location;

      for(int i=0; i < size; i++){
        if(gameBoard[i] == playerEntry){
          num_location= i;
          //printf("\n%d\n", num_location);
        }   
      }

      int zero_location;

      for(int i=0; i < size; i++){
        if(gameBoard[i] == 0){
          zero_location=i;
          //printf("\n%d\n", zero_location);
        }

      }

      if(zero_location + 1 == num_location || zero_location - 1 == num_location || zero_location + cols == num_location || zero_location - cols == num_location){
        if ((zero_location+1) % cols == 0 && num_location == zero_location+1){
          printf("\nNumber cannot be moved");
        }
        if(zero_location % cols == 0 && num_location == zero_location-1){
          printf("\nNumber cannot be moved");
        }
        else{
          gameBoard[zero_location] = gameBoard[num_location];
          gameBoard[num_location]=0;
        }
      }
      else{
        printf("\nNumber cannot be moved");
      }

    }while(playerEntry != 0);

    printf("\ndo you want to keep playing. Yes(1), No(0): \n");
    int keepPlaying;
    scanf("%d", &keepPlaying);
    if(keepPlaying != 1){
      break;
    }

  }while(1);
  
  printf("GoodBye!\n");

	return 0;
}
*/

