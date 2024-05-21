#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int game(char comp,char player);        //defined a function
int main(){
  char comp;                      
  char player;                   
  int countc=0;
  int countp=0;
  for(int i=1;i<=3;i++){                             //making it a best of three game
    printf("enter the chracter r/p/s:");            //takes the input from user
    scanf(" %c",&player);
    srand(time(0));                               //selecting a random number
    if(player!='r'&&player!='s'&&player!='p'){   //check if right character is entered
      printf("enter the right character\n");
      break;
    }
    int number=rand()%100+1;
    if(number<=33){                          //makes equal probability of chosing a numberthat is one-third
      comp='r';
    }
    else if (number >33 && number <=66){
      comp='p';
    }
    else {
      comp='s';
    }
    int winner =game(comp,player);
    if(winner==1){                  
      countp++;                    //gives one point to player
      printf("you win the round\n");
    }
    else if (winner==-1)
    {
      countc++;                //gives one point to computer
     printf("you lost the round\n");
    }
    else{
      printf("this round is a draw\n");
    }
   
    }
    if(countc>countp){                         
      printf("hard luck you lost\n");
      
    }
    else if (countp>countc){
      printf("yay you won \n");
    }
    else{
      printf("it's a tie");
    }
  return 0;
}
int game(char comp,char player){         //function definition computer selecting a character 
  if(comp=='r'&& player=='p'){    
   return 1;                           //win case returns 1 means player wins
  }
  else if(comp=='r'&& player=='s'){
    return -1;
  }
  else if(comp=='p'&& player=='s'){
  return 1;
  }
  else if(comp=='p'&& player=='r'){ //lose case returns -1 means player lose
  return -1;
  }
  else if(comp=='s'&& player=='r'){
  return 1;
  }
  else if(comp=='s'&& player=='p'){
  return -1;
  }
  else if(comp==player){         //draw case returns 0 both wins
    return 0;
  }
}
