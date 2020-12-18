#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct color
{
   int redPos;
   int greenPos;
   int bluePos;
} Color;

void quickSort(int arr[], int high, int low, int size);
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
   int size;
   printf("\nEnter Size of Array : ");
   scanf("%d", &size);

   int *array = (int *)malloc(size * sizeof(int));
   checkErrMalloc(array);

   generateArray(&array, size);
   insertionSort(array, size);
   // bubbleSort(array, size);
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
      while (j >= 0 && arr[j] > key)
      {

         indices.redPos = i;
         indices.bluePos = j;
         printInsertionSort(arr, size, &indices);
         system("cls");
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
      indices.redPos = i;
      indices.bluePos = j;
      printInsertionSort(arr, size, &indices);
   }
}

void printInsertionSort(int arr[], int size, Color *indices)
{
   int i, j;
   for (i = 0; i < size; i++)
   {
      addColor(indices, i);
      printBar(arr[i]);
      printf("\033[0m");
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