#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define STACK_SIZE 5 // max stack size

// stack implementation with array

void push(int);
int pop();
int isUnderflow();
int isOverflow();
void printFullStack();


int stack[STACK_SIZE];
int head = -1;

int main(){
    char choice;
    int temp; 

        while(1){
            
            system("cls");
            printf(" *** Stack menu driven program *** \r\n\r\n");

            printf("For push: +\r\n");
            printf("For pop: -\r\n");
            printf("To check underflow: _ \r\n");
            printf("To check overflow: ^ \r\n");
            printf("To print full stack: = \r\n");
            printf("To exit : < \r\n");
            printf("Your choice: ");
            scanf("%c", &choice);

            switch (choice)
            {
            case '+':
                if(!isOverflow()){
                    printf("Enter element: ");
                    scanf("%d", &temp);
                    push(temp);
                    
                }
                else{
                    printf("Stack is full! Overflow condition!!!\r\n");
                    getch();
                }

                fflush(stdin); // clearning buffer caused by getch
                break;
                
            case '-':
                if(!isUnderflow()){
                    printf("Popped element is: %d", pop());
                    
                }
                else
                    printf("Stack is empty! Underflow condition!!!\r\n");

                getch();
                fflush(stdin);
                break;
            

            case '_':
                if(isUnderflow())
                    printf("Empty! Underflow!!!\r\n");

                else
                    printf("No Underflow. There are %d space is empty!", STACK_SIZE - (head + 1));

                getch();
                fflush(stdin);
                break;

            case '^':
                if (isOverflow())
                    printf("Full! Overflow!!!\r\n");
                    
                else
                    printf("No Overflow. There are %d space is empty!", STACK_SIZE - (head + 1));

                getch();
                fflush(stdin);
                break;

            case '=':
                if (isUnderflow())
                    printf("Empty! Underflow!!!\r\n");

                else
                    printFullStack();
                
                getch();
                fflush(stdin);
                break;

            case '<':
                printf("Exiting...\r\n");
                Sleep(1000);
                exit(0);
                break;

            default:
                printf("Please Enter a valid choice!");
                getch();
                fflush(stdin);
                
    }
}

    getch();
    return 0;
}

// functions

void push(int x){
        head++;
        stack[head] = x;
}

int pop(){
    head-- ;
    return stack[head+1];
}

int isOverflow(){
    return head==STACK_SIZE-1?1:0;
}

int isUnderflow(){
    return head == -1 ? 1 : 0;
}

void printFullStack(){
    
        printf("Stack contains: \r\n");
        for(int i=head; i>=0; i--)
            printf(" | %d |\r\n", stack[i]);

        printf(" |---| \r\n");

        if(!isOverflow())
            printf("--- There are %d element space is empty\r\n", STACK_SIZE - (head + 1));
    
}