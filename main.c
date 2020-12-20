#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "treeSort.h"

typedef struct color
{
   int redPos;
   int greenPos;
   int bluePos;
} Color;

void quickSort(int arr[], int high, int low, int size);
void printQuickSort(int arr[], int size);
void printBar(int value);
void generateArray(int **arr, int size);
void checkErrMalloc(int *ptr);
void printBubbleSort(int *arr, int size, Color *Indices);
void swap(int *n1, int *n2);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void printInsertionSort(int arr[], int size, Color *indices);
void addColor(Color *Indices, int index);
void delay(float numberOfSeconds);
/*function prototype*/
int main()
{
   int size = 1;
   while (size != 0)
   {
      system("cls");
      printf("SORTING VISUALIZER\nEnter Size of Array (Enter 0 to Exit Program) : ");
      scanf("%d", &size);
      int *array = (int *)malloc(size * sizeof(int));
      generateArray(&array, size);
      checkErrMalloc(array);
      int opt = 1;
      while (opt != 0)
      {
         system("cls");
         printf("Select Which Sorting Algortihm To Visualize :\n[1] Bubble Sort\n[2] Insertion Sort\n[3] Quick Sort\n[4] Tree Sort\n\n[ 0] Generate New Array\n[-1] Exit Program\n");
         scanf("%d", &opt);
         switch (opt)
         {
         case -1:
            size = 0;
            opt = 0;
            break;
         case 0:
            opt = 0;
            break;
         case 1:
            bubbleSort(array, size);
            break;
         case 2:
            insertionSort(array, size);
            break;
         case 3:
            printf("\nQuick Sort is Not Available for Now");
            break;
         case 4:
            treeSort(array, size);
            break;
         default:
            break;
         }
      }
      free(array);
   }
   // insertionSort(array, size);
   // bubbleSort(array, size);
   // quickSort(array, size - 1, 0, size);
   return 0;
}

void generateArray(int **arrPtr, int size)
{
   int *arr = *arrPtr;
   srand(time(NULL));
   int i;
   printf("\n[  ");
   for (i = 0; i < size; i++)
   {
      arr[i] = 1 + (rand() % size);
      printf("%d  ", arr[i]);
   }
   printf("]\n");
   printf("\nPress Anything to Continue");
   getch();
}

void quickSort(int arr[], int high, int low, int size)
{
   int i;
   int pivot = arr[high];
   int swapIndex = low - 1;
   system("cls");
   if (low < high)
   {
      for (i = low; i < high; i++)
      {
         if (arr[i] <= pivot)
         {
            swapIndex++;
            swap(&arr[i], &arr[swapIndex]);
            printQuickSort(arr, size);
            system("cls");
         }
      }
      swap(&arr[high], &arr[swapIndex + 1]);
      printQuickSort(arr, size);
      quickSort(arr, swapIndex, low, size);
      quickSort(arr, high, swapIndex + 2, size);
   }
}
void printQuickSort(int arr[], int size)
{
   int i, j;
   for (i = 0; i < size; i++)
   {
      printBar(arr[i]);
      printf("\033[0m");
   }
   printf("\033[0m");
   printf("\nPress Anything to Continue");
   getch();
}

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
         printf("\nindices.greenPos = %d, i = %d\n", indices.greenPos, i);
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

void insertionSort(int arr[], int size)
{
   int i, j;
   int key;
   // printf("%d   %d\n", arr[low], arr[p]);
   Color indices;
   for (i = 1; i < size; i++)
   {
      key = arr[i];
      j = i - 1;
      system("cls");
      indices.redPos = -1;
      indices.greenPos = i;
      printInsertionSort(arr, size, &indices);
      while (j >= 0 && arr[j] > key)
      {
         system("cls");
         indices.redPos = j;
         swap(&arr[j + 1], &arr[j]);
         j = j - 1;
         printInsertionSort(arr, size, &indices);
      }
   }
   system("cls");
   indices.greenPos = -1;
   printInsertionSort(arr, size, &indices);
}

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

void addColor(Color *Indices, int index)
{
   if (index == Indices->redPos)
   {
      printf("\033[1;31m");
   }
   if (index == Indices->bluePos)
   {
      printf("\033[1;34m");
   }
   if (index == Indices->greenPos)
   {
      printf("\033[1;32m");
   }
}

void printBar(int value)
{
   // printf("%3d", value);
   int i; /*counter*/
   for (i = 0; i < value; i++)
   {
      printf("|");
   }
   printf("\n");
}

void swap(int *n1, int *n2)
{
   int temp;
   temp = *n1;
   *n1 = *n2;
   *n2 = temp;
}

void checkErrMalloc(int *ptr)
{
   if (ptr == NULL)
   {
      printf("\nERROR! MEMORY CANNOT BE ALLOCATED");
      exit(0);
   }
}
void delay(float numberOfSeconds) //function to delay or take time
{
   // Converting time into milli_seconds
   int milliSeconds = 1000 * numberOfSeconds;

   // Storing start time
   clock_t startTime = clock();

   // looping till required time is not achieved
   while (clock() < startTime + milliSeconds)
      ;
}