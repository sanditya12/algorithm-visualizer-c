#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "color.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "treeSort.h"
#include "mergeSort.h"

void printBar(int value);
void generateArray(int **arr, int size);
void checkErrMalloc(int *ptr);
void swap(int *n1, int *n2);
void delay(float numberOfSeconds);
/*function prototype*/
int main()
{
   int size = 1;
   while (size != -1)
   {
      system("cls");
      printf("SORTING VISUALIZER\nfor better experience, please enlarge this window size!\n\nEnter Size of Array (Enter -1 to Exit Program) : ");
      scanf("%d", &size);
      int *array = (int *)malloc(size * sizeof(int));
      generateArray(&array, size);
      checkErrMalloc(array);
      int opt = 1;
      while (opt != 0)
      {
         system("cls");
         printf("Select Which Sorting Algortihm To Visualize :\n[1] Bubble Sort\n[2] Insertion Sort\n[3] Tree Sort\n[4] Merge Sort\n\n[ 0] Generate New Array\n[-1] Exit Program\n");
         scanf("%d", &opt);
         switch (opt)
         {
         case -1:
            size = -1;
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
            treeSort(array, size);
            break;
         case 4:
            mergeSort(array, 0, size - 1, size);

         default:
            break;
         }
      }
      free(array);
   }
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