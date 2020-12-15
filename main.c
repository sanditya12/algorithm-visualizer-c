#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void quickSort(int arr[], int high, int low);
void printBar(int value);

int main()
{
   int arr[7] = {2, 10, 5, 5, 3, 3, 7};
   quickSort(arr, 7, 0);

   return 0;
}

void quickSort(int arr[], int high, int low)
{
   int i;
   int p = high - 1;
   int temp;
   int swapIndex = 0;
   // printf("%d   %d\n", arr[low], arr[p]);

   if (low < p)
   {
      system("cls");
      for (i = 0; i < high; i++)
      {

         if (arr[i] < arr[p])
         {
            temp = arr[i];
            arr[i] = arr[swapIndex];
            arr[swapIndex] = temp;
            swapIndex++;
         }
      }
      temp = arr[swapIndex];
      arr[swapIndex] = arr[p];
      arr[p] = temp;
      for (i = 0; i < 7; i++)
      {
         printBar(arr[i]);
      }
      printf("\nPress Anything to Continue");
      getch();

      quickSort(arr, swapIndex, low);
      quickSort(arr, high, swapIndex + 1);
   }
}

void printBar(int value)
{
   int i;
   for (i = 0; i < value; i++)
   {
      printf("|");
   }
   printf("\t\t\t%3d\n", value);
}