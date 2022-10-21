/*C program to implement the concept of Dining philosopher problem*/

#include<stdio.h>
#include<stdlib.h>

void EatingCompleted();
void WantToEat();

char state[5]={'T','T','T','T','T'};
char chop[5]={'F','F','F','F','F'};

void WantToEat(){
  int p,i;
 printf(" Which philosopher want to eat");
 scanf("%d",&p);

 if(state[p]=='T' && chop[p]=='F'&& chop[(p+1)%5]=='F'){
     state[p]='E';
     chop[p]=chop[(p+1)%5]='B';
    }
 else if(state[p]=='T'){
     state[p]='H';
   }
 else {
   printf("\nPhilosopher is eating or Hungry.\n");
 }
printf("\nDining Status after operation \n");
for(i=0;i<5;i++){

       
        printf("Philosopher no.= %d state= %c chopstick no. %d= %c \n",i,state[i],i,chop[i]);
      }
}

void EatingCompleted(){
   
int p,i;
 printf("\n Which philosopher want to stop eating \n ");
 scanf("%d",&p);
if(state[p]=='E' && chop[p]=='B'&& chop[(p+1)%5]=='B'){
     state[p]='T';
     chop[p]=chop[(p+1)%5]='F';
     for(i=0;i<5;i++){
        if(state[i]=='H' && chop[i]=='F'&& chop[(i+1)%5]=='F'){
          state[i]='E';
          chop[i]=chop[(i+1)%5]='B';
        }
 
      }
  }
 else{
   printf("\n Philosopher is thinking \n");
}
printf("\nDining Status after operation : \n");
for(i=0;i<5;i++){

        
        printf("Philosopher no.= %d state= %c chopstick no. %d= %c \n",i,state[i],i,chop[i]);
      }
}

void main(){
  char state[5]={'T','T','T','T','T'};
  char chop[5]={'F','F','F','F','F'};
while(1){
    int i,choice; 
     for(i=0;i<5;i++){

        printf("Present Dining Status : ");
        printf("Philosopher no.= %d state= %c chopstick no. %d= %c \n",i,state[i],i,chop[i]);
      }
     printf("\n 1. Want to eat \n 2. Eating Completed \n 3. Exit \n");
     printf("enter your choice ");
     scanf("%d",&choice);
    
 //Starting of switch case statement
switch(choice){

    case 1:  WantToEat();
              break;
    case 2:  EatingCompleted();
              break;
    case 3:  exit(0);
 
    default : printf("Wrong Choice!!!!");
   }
 }
}