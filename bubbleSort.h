#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printBubbleSort(int *arr, int size, Color *Indices);
void bubbleSort(int arr[], int size);
void printBar(int value);
void swap(int *n1, int *n2);
void delay(float numberOfSeconds);

//sorting
void bubbleSort(int arr[], int size)
{
   system("cls");
   int i, j;
   Color indices;
   for (i = 0; i < size - 1; i++)
   {
      for (j = 0; j < size - 1 - i; j++)
      {
         indices.bluePos = j;                             /*red indicates index j or the index that is currently being compared to the next element*/
         indices.greenPos = size - i == 2 ? 0 : size - i; /*green indicates the sorted element's index*/
         printBubbleSort(arr, size, &indices);
         indices.redPos = -1;
         system("cls");
         if (arr[j] > arr[j + 1])
         {
            swap(&arr[j], &arr[j + 1]);
            indices.redPos = j; /*red indicates that there is a swap happening*/
         }
      }
   }
   printBubbleSort(arr, size, &indices);
}

/*function used to print or visualize the bubble sort Algorithm*/
void printBubbleSort(int *arr, int size, Color *Indices)
{
   int i; /*counter*/
   for (i = 0; i < size; i++)
   {
      addColor(Indices, i);
      printBar(arr[i]);
      if (i < Indices->greenPos)
      {
         printf("\033[0m");
      }
   }
   printf("\033[0m");
   printf("\nPress Anything to Continue");
   getch();
   // delay(((float)3) / size);
}