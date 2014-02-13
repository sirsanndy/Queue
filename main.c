#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <conio2.h>

void push(int *maxqueue, int *rear, int *numbers){
    int number;
    if(*rear<*maxqueue){
       textcolor(YELLOW);
       gotoxy(5,*rear+1);
       scanf("%i", &number);
       numbers[*rear]=number;
       ++*rear;
    }
}

void pop(int *maxqueue,int *front, int *rear, int *numbers){
     int i;
    if(*front!=*rear){
       numbers[*front]=0;
       ++*front;
    }else{numbers[*rear]=0;
          textcolor(LIGHTRED);printf("Antrian kosong\n");
          }
}
void cetak(int *front, int *rear, int *numbers){
   int i;
   for(i=*front;i<=*rear;i++){
        gotoxy(5,8+i);printf("%i\n",numbers[i]);
    }
}
int main(int argc, char *argv[])
{   int numbers[5];
    int front, rear, maxqueue;
    int i = 0;

    maxqueue = 5;
    front = 0;
    rear = 0;
    while(rear<maxqueue){
        push(&maxqueue, &rear, numbers);
    }
    --rear;
    textcolor(LIGHTGREEN);
    pop(&maxqueue,&front, &rear, numbers);
    printf("-------------\n");
    textcolor(LIGHTCYAN);
    gotoxy(1,7);printf("POP pertama");
    textcolor(LIGHTGREEN);
    cetak(&front, &rear, numbers); 
    printf("-------------\n");
    textcolor(LIGHTCYAN);
    gotoxy(1,14);printf("POP kedua\n");
    while(front<=rear &&numbers[rear]!=0){
                   pop(&maxqueue,&front, &rear, numbers); 
    }
    textcolor(LIGHTBLUE);
  system("pause");	
  return 0;
}
