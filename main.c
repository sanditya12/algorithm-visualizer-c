#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void quickSort(int arr[], int high, int low, int size);
void printBar(int value);
void generateArray(int **arr, int size);
void checkErrMalloc(int *ptr);
void printArray(int *arr, int size, int counterPos);
void swap(int *n1, int *n2);
void bubbleSort(int arr[], int size);
/*function prototype*/
int main()
{
   int size;
   printf("\nEnter Size of Array : ");
   scanf("%d", &size);

   int *array = (int *)malloc(size * sizeof(int));
   checkErrMalloc(array);

   generateArray(&array, size);
   bubbleSort(array, size);
   // printArray(array, size);

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
   int pivot = high - 1;
   int swapIndex = 0;
   system("cls");
   if (low < pivot)
   {
      for (i = 0; i < high; i++)
      {
         if (arr[i] < arr[pivot])
         {
            swap(&arr[i], &arr[swapIndex]);
            swapIndex++;
         }
      }
      swap(&arr[pivot], &arr[swapIndex]);
      // printArray(arr, size);
      quickSort(arr, swapIndex, low, size);
      quickSort(arr, high, swapIndex + 1, size);
   }
}

void bubbleSort(int arr[], int size)
{
   int i, j;
   for (i = 0; i < size - 1; i++)
   {
      for (j = 0; j < size - 1 - i; j++)
      {
         system("cls");
         printArray(arr, size, j);
         if (arr[j] > arr[j + 1])
         {
            swap(&arr[j], &arr[j + 1]);
         }
      }
   }
}

void printArray(int *arr, int size, int counterPos)
{
   int i; /*counter*/
   for (i = 0; i < size; i++)
   {
      if (i == counterPos)
      {
         printf("\033[1;32m");
         printBar(arr[i]);
         printf("\033[0m");
      }
      else
      {
         printBar(arr[i]);
      }
   }
   printf("\nPress Anything to Continue");
   getch();
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