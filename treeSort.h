#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Sanditya Larope Sutanto
// 1906423183

struct treeNode
{
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

struct queueNode
{
   TreeNodePtr node;
   struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void insert(TreeNodePtr *treePtr, int data);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr data);
void printSpace(int amount);
void traverseInOrder(TreeNodePtr treePtr);
void printArray(int arr[], int size, int currentIndex);
void printByLevel(TreeNodePtr treePtr);
int findDepth(TreeNodePtr treePtr);
int findSpace(int n);
int power(int num, int x);
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);

void treeSort(int arr[], int size)
{
   TreeNodePtr rootPtr = NULL; /*declare root pointer*/
   int data;
   int depth;
   int i;

   printf("[BINARY TREE]");

   for (i = 0; i < size; i++)
   {
      system("cls");
      insert(&rootPtr, arr[i]); /*insert to binary tree*/

      printArray(arr, size, i); /*print unsorted array*/

      printf("\nThe Tree Diagram :\n");
      printByLevel(rootPtr); /*visualize the tree diagram*/
      printf("\nPress Anything to Continue");
      getch();
   }
   printf("Using InOrder Traversal, the Sorted Array is,\n");
   traverseInOrder(rootPtr); /*traverse in order to sort*/
   printf("\n\n\nPress Anything to Continue");
   getch();
}

/*print the unsorted array and show the current element that is inserted into the binary tree by using color*/
void printArray(int arr[], int size, int currentIndex)
{
   int i;
   for (i = 0; i < size; i++)
   {
      if (i == currentIndex)
      {
         printf("\033[1;32m%d  \033[0m", arr[i]);
      }
      else
      {
         printf("%d  ", arr[i]);
      }
   }
}

//binary tree
void insert(TreeNodePtr *treePtr, int data)
{

   if (*treePtr == NULL)
   {

      *treePtr = malloc(sizeof(TreeNode));

      if (*treePtr == NULL)
      {
         printf("\n%c Cannot be Inserted into the Tree, Because There Are No Memory Available\n");
      }
      else
      {

         (*treePtr)->data = data;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      }
   }
   else
   {
      if (data < (*treePtr)->data)
      {
         insert(&(*treePtr)->leftPtr, data);
      }
      else if (data >= (*treePtr)->data) /*in this tree, the duplicates is placed on the right side of the root*/
      {
         insert(&(*treePtr)->rightPtr, data);
      }
   }
}

//enqueue
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr data)
{ /*used to enqueue*/
   QueueNodePtr tempPtr;

   tempPtr = malloc(sizeof(QueueNode));

   if (tempPtr != NULL)
   {
      tempPtr->node = data;
      tempPtr->nextPtr = NULL;

      if (*headPtr == NULL)
      {
         *headPtr = tempPtr;
      }
      else
      {
         (*tailPtr)->nextPtr = tempPtr;
      }
      *tailPtr = tempPtr;
   }
   else //if memory cannot be allocated
   {
      printf("ERROR! (Memory not Available)");
   }
}

//queue
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{ /*used to dequeue*/
   QueueNodePtr tempPtr;

   TreeNodePtr data = (*headPtr)->node;
   tempPtr = *headPtr;
   *headPtr = (*headPtr)->nextPtr;

   if (*headPtr == NULL)
   {
      *tailPtr = NULL;
   }
   free(tempPtr);

   return data; //return the nodeptr
}

/*printByLevel function is used to print or visualize the binary tree in the terminal */
void printByLevel(TreeNodePtr treePtr)
{
   int depth = findDepth(treePtr); //find the depth of tree

   int nullNode = 0, level = 0;
   /*nullNode is used to break the loop when it dequeue two consecutive NULL nodeptr
   level is used to describe the current depth*/

   QueueNodePtr headPtr = NULL;
   QueueNodePtr tailPtr = NULL;
   TreeNodePtr current;
   TreeNodePtr tempPtr;

   TreeNodePtr zero = malloc(sizeof(TreeNode)); /*inirialize dummy node*/
   zero->data = 0;
   zero->leftPtr = NULL;
   zero->rightPtr = NULL;

   enqueue(&headPtr, &tailPtr, treePtr);
   enqueue(&headPtr, &tailPtr, NULL);

   printSpace(findSpace(depth - level));

   while (nullNode < 2)
   {
      current = dequeue(&headPtr, &tailPtr);

      if (current == NULL) /*if the dequeue ptr is the delimiter, indicates new level*/
      {
         enqueue(&headPtr, &tailPtr, NULL);
         level++;
         nullNode++;
         if (nullNode == 1)
         {
            printf("\n\n");
            printSpace(findSpace(depth - level));
         }
      }
      else
      {
         nullNode = 0;
         if (current->leftPtr != NULL) /*enqueue the right pointer of a root*/
         {
            enqueue(&headPtr, &tailPtr, current->leftPtr);
         }
         else if (depth - level > 0) /*if the node is empty, fill with dummy node*/
         {
            enqueue(&headPtr, &tailPtr, zero);
         }
         if (current->rightPtr != NULL) /*enqueue the right pointer of a root*/
         {
            enqueue(&headPtr, &tailPtr, current->rightPtr);
         }
         else if (depth - level > 0) /*if the node is empty, fill with dummy node*/
         {
            enqueue(&headPtr, &tailPtr, zero);
         }
         if (current->data != 0) /*doesn't print dummy node*/
         {
            printf("%d", current->data);

            printSpace(findSpace(depth - level + 1));
         }
         else
         {
            printSpace(findSpace(depth - level + 1) + 1);
         }
      }
   }
}

/*findDepth function is used to find the depth of the tree, return how many levels*/
int findDepth(TreeNodePtr treePtr)
{
   if (treePtr == NULL)
   {
      return 0;
   }
   else
   {
      int left = findDepth(treePtr->leftPtr);
      int right = findDepth(treePtr->rightPtr);
      if (left > right)
      {
         return left + 1;
      }
      else
      {
         return right + 1;
      }
   }
}

/*find the right amount of space to print a node of the tree*/
int findSpace(int n)
{
   return ((power(2, n) - 1));
}

/*function to power an integer*/
int power(int num, int x)
{
   int i;
   int total = 1;
   for (i = 0; i < x; i++)
   {
      total = total * num;
   }
   return total;
}

/*print certain amount of space*/
void printSpace(int amount)
{
   int i;
   for (i = 0; i < amount; i++)
   {
      printf(" ");
   }
}

/*traverse tree in order*/
void traverseInOrder(TreeNodePtr treePtr)
{
   if (treePtr != NULL)
   {
      traverseInOrder(treePtr->leftPtr);
      printf("%d  ", treePtr->data);
      traverseInOrder(treePtr->rightPtr);
   }
}
