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
      /*enter array size*/
      system("cls");
      printf("SORTING VISUALIZER\nfor better experience, please enlarge this window size!\n\nEnter Size of Array (Enter -1 to Exit Program) : ");
      scanf("%d", &size);

      //array and memory allocation
      int *array = (int *)malloc(size * sizeof(int));
      generateArray(&array, size);
      checkErrMalloc(array);

      int opt = 1;
      /*sorting menu*/
      while (opt != 0)
      {
         system("cls");
         printf("Select Which Sorting Algortihm To Visualize :\n[1] Bubble Sort\n[2] Insertion Sort\n[3] Tree Sort\n[4] Merge Sort\n\n[ 0] Generate New Array\n[-1] Exit Program\n");
         scanf("%d", &opt);
         switch (opt)
         {
         case -1: /*exit program*/
            size = -1;
            opt = 0;
            break;
         case 0: /*back to generate array menu*/
            opt = 0;
            break;
         case 1: /*proceed to bubble sort visualizer*/
            bubbleSort(array, size);
            break;
         case 2: /*proceed to insertion sort visualizer*/
            insertionSort(array, size);
            break;
         case 3: /*proceed to tree sort visualizer*/
            treeSort(array, size);
            break;
         case 4: /*proceed to merge sort visualizer*/
            mergeSort(array, 0, size - 1, size);
         default:
            break;
         }
      }
      free(array);
   }
   return 0;
}

/*function to fill the array with random elements*/
void generateArray(int **arrPtr, int size)
{
   //pointer
   int *arr = *arrPtr;
   srand(time(NULL));
   int i;
   printf("\n[  ");
   for (i = 0; i < size; i++)
   {
      //rand function
      arr[i] = 1 + (rand() % size);
      printf("%d  ", arr[i]);
   }
   printf("]\n");
   printf("\nPress Anything to Continue");
   getch();
}

/*print the value of an element in the array by printing the character '|' according to the value of the element*/
void printBar(int value)
{
   int i; /*counter*/
   for (i = 0; i < value; i++)
   {
      printf("|");
   }
   printf("\n");
}

//pointer
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