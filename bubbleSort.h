#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printBubbleSort(int *arr, int size, Color *Indices);
void bubbleSort(int arr[], int size);
void printBar(int value);
void generateArray(int **arr, int size);
void checkErrMalloc(int *ptr);
void swap(int *n1, int *n2);
void delay(float numberOfSeconds);

void bubbleSort(int arr[], int size)
{
   system("cls");
   int i, j;
   Color indices;
   for (i = 0; i < size - 1; i++)
   {
      for (j = 0; j < size - 1 - i; j++)
      {
         indices.bluePos = j;
         indices.greenPos = size - i == 2 ? 0 : size - i;
         printBubbleSort(arr, size, &indices);
         indices.redPos = -1;
         system("cls");
         if (arr[j] > arr[j + 1])
         {
            swap(&arr[j], &arr[j + 1]);
            indices.redPos = j;
         }
      }
   }
   printBubbleSort(arr, size, &indices);
}

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