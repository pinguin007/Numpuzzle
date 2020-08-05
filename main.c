/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>


int main(void) {
  int keepPlaying=1;
  int playerEntry;

  while(keepPlaying){
    int rows;
    int cols;
    while(rows<3||cols<3|| rows>8|| cols>8){
      printf("please enter the number of rows: \n");
      scanf("%d", &rows);

      printf("please enter the number of columns: \n");
      scanf("%d", &cols);
    }
    
    int size= rows*cols;
    int orderedBoard[size];
    int gameBoard[size];
    
    for(int i=0; i <= size; i++){
      orderedBoard[i]=i;
    }

    int j=0;
    srand( time(NULL) );
    while(j < (size-1)){
          int flag=0;
          int random= rand() % size;
          
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
    gameBoard[size]=0;

    orderedBoard[size-1]=0;


    int playerEntry=1;

    while(playerEntry != 0){
      
        int count=0;
        char emptystring[2];
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
        else if(zero_location % cols == 0 && num_location == zero_location-1){
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

    }
    printf("\ndo you want to keep playing. Yes(1), No(0): \n");
    scanf("%d", &keepPlaying);
    }
  }
  
*/