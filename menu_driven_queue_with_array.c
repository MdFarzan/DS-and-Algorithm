#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define QUEUE_SIZE 5 // max size of queue


/*  menu driven program of queue implementation with array */


void insertQ();
int removeQ();
int isUnderflowQ();
int isOverflowQ();
void printQ();


int queue[QUEUE_SIZE];
int index = -1;

int main(){
    char choice;
    int temp;
    while(1){
        system("cls");
        printf("*** Menu driven program of Queue with array *** \r\n\r\n");

        printf("To insert: +\r\n");
        printf("To remove: -\r\n");
        printf("To check overflow: ^\r\n");
        printf("To check underflow: _\r\n");
        printf("To print queue: =\r\n");
        printf("For exit: <\r\n");
        printf("Your choice: ");
        
        scanf("%c", &choice);

        switch(choice){
            case '+':
                if(isOverflowQ()){
                    printf("Queue is full! Overflow!!!\r\n");
                    getch();
                    
                }

                else{
                    printf("Enter number to insert: ");
                    scanf("%d", &temp);
                    insertQ(temp);
                }
                fflush(stdin);
                break;

            case '-':
                if(isUnderflowQ())
                    printf("Queue is empty! Underflow!!!\r\n");

                else{
                    temp = removeQ();
                    printf("Removed element: %d\r\n", temp);
                }        
                
                getch();
                fflush(stdin);
                break;

            case '^':
                if(isOverflowQ())
                    printf("Overflow!");

                else
                    printf("No overflow, %d space is empty.", QUEUE_SIZE - (index + 1));

                getch();
                fflush(stdin);
                break;

            case '_':
                if (isUnderflowQ())
                    printf("Underflow!");

                else
                    printf("No underflow, only %d space is empty.", QUEUE_SIZE - (index + 1));

                getch();
                fflush(stdin);
                break;

            case '=':
                if(isUnderflowQ())
                    printf("Queue is empty! Underflow!!!");

                else{
                    printf("Queue Elements are: \r\n");
                    printQ();
                }
                getch();
                fflush(stdin);
                break;

            case '<':
                printf("Exiting...\r\n");
                Sleep(1000);
                exit(0);
                break;

            default:
                printf("Please enter a valid choice!");
                getch();
                fflush(stdin);

        }
        
    }

    getch();
    return 0;
}

void insertQ(int x){
    index++;
    queue[index] = x;
}

int removeQ(){
    int temp = queue[0];

    for(int i=0; i<index; i++)
        queue[i] = queue[i+1];

    index--;
    return temp;
}

int isUnderflowQ(){
    return index == -1?1:0;
}

int isOverflowQ(){
    return index == QUEUE_SIZE -1 ? 1 : 0;
}

void printQ(){
    for(int i=0; i<=index; i++)
        printf("%d\t", queue[i]);
    
    printf("\r\n");
    printf("--%d space is empty in queue", QUEUE_SIZE - (index + 1));
}
