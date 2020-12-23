#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void printBar(int value);
void swap(int *n1, int *n2);
void delay(float numberOfSeconds);

/*function used to print or visualize the mergesort Algorithm*/
void printMergeSort(int arr[], int size, Color indices)
{
   system("cls");
   int i;
   for (i = 0; i < size; i++)
   {
      addColor(&indices, i);
      printBar(arr[i]);
      printf("\033[0m");
   }
   printf("\nPress Anything to Continue");
   getch();
}

void merge(int arr[], int l, int m, int r, int size)
{
   Color indices;
   indices.greenPos = -1;
   indices.bluePos = -1;
   indices.redPos = -1;

   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   /* create temp arrays */
   int L[n1], R[n2];

   /* Copy data to temp arrays L[] and R[] */
   for (i = 0; i < n1; i++)
   {
      L[i] = arr[l + i];
   }
   for (j = 0; j < n2; j++)
   {
      R[j] = arr[m + 1 + j];
   }

   /* Merge the temp arrays back into arr[l..r]*/
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2)
   {
      indices.greenPos = k;
      printMergeSort(arr, size, indices);
      if (L[i] <= R[j])
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   /* Copy the remaining elements of L[], if there
    are any */
   while (i < n1)
   {
      indices.greenPos = k;
      printMergeSort(arr, size, indices);
      arr[k] = L[i];
      i++;
      k++;
   }

   /* Copy the remaining elements of R[], if there
    are any */
   while (j < n2)
   {
      indices.greenPos = k;
      printMergeSort(arr, size, indices);
      arr[k] = R[j];
      j++;
      k++;
   }
}

//sorting
void mergeSort(int arr[], int l, int r, int size)
{
   if (l < r)
   {

      int m = l + (r - l) / 2;

      mergeSort(arr, l, m, size);
      mergeSort(arr, m + 1, r, size);
      merge(arr, l, m, r, size);
   }
}