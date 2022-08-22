#include <stdio.h>
#include <conio.h>

void sortAsc(int [], int);
void sortDesc(int[], int);
void output(int[], int);

int main(){

    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int n = 10; //number of elements

    sortAsc(arr, 10);

    output(arr, 10);

    sortDesc(arr, 10);

    output(arr, 10);


    getch();
    return 0;
}

void sortAsc(int arr[], int length){
    int temp;
    for(int i=0; i<length-1; i++)
        for(int j=0; j<length-i-1; j++)
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

}

void sortDesc(int arr[], int length){
    int temp;
    for(int i=0; i<length-1; i++)
        for(int j=0; j<length-i-1; j++)
            if(arr[j] < arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

}

void output(int arr[], int length){
    printf("Array contains:\r\n");
    for(int i=0; i<length; i++)
        printf("%d  ", arr[i]);

    printf("\r\n");
}