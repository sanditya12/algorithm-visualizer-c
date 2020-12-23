#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insertionSort(int arr[], int size);
void printInsertionSort(int arr[], int size, Color *indices);
void printBar(int value);
void swap(int *n1, int *n2);

//sorting
void insertionSort(int arr[], int size)
{
   int i, j;
   int key;
   Color indices;
   for (i = 1; i < size; i++)
   {
      key = arr[i];
      j = i - 1;
      system("cls");
      indices.redPos = -1;
      indices.greenPos = i; /*green indicate the key value position*/
      printInsertionSort(arr, size, &indices);
      while (j >= 0 && arr[j] > key)
      {
         system("cls");
         indices.redPos = j; /*red indicate the which value is currently compared with the key value*/

         swap(&arr[j + 1], &arr[j]);
         j = j - 1;
         printInsertionSort(arr, size, &indices);
      }
   }
   system("cls");
   indices.greenPos = -1;
   printInsertionSort(arr, size, &indices);
}

/*function used to print or visualize the insertion sort Algorithm*/
void printInsertionSort(int arr[], int size, Color *indices)
{
   int i, j;
   for (i = 0; i < size; i++)
   {
      addColor(indices, i);
      if (indices->greenPos == -1)
      {
         printf("\033[1;32m");
         printBar(arr[i]);
      }
      else
      {
         printBar(arr[i]);
         printf("\033[0m");
      }
   }
   printf("\033[0m");
   printf("\nPress Anything to Continue");
   getch();
}