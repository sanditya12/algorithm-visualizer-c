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

//function prototypes

void treeSort(int arr[], int size)
{
   TreeNodePtr rootPtr = NULL; //declare root pointer
   int data;                   //decare character variable
   int depth;
   int i;

   printf("[BINARY TREE]"); //title

   for (i = 0; i < size; i++)
   {
      system("cls");
      insert(&rootPtr, arr[i]); //call function to insert
      printArray(arr, size, i);
      printf("\nThe Tree Diagram :\n");
      printByLevel(rootPtr);
      printf("\nPress Anything to Continue");
      getch();
   }
   printf("Using InOrder Traversal, the Sorted Array is,\n");
   traverseInOrder(rootPtr);
   printf("\n\n\nPress Anything to Continue");
   getch();
}

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

//insert node of tree and find place to insert
void insert(TreeNodePtr *treePtr, int data)
{
   //check if node is empty
   if (*treePtr == NULL)
   {
      //allocate memory
      *treePtr = malloc(sizeof(TreeNode));

      //if memory cannot be allocated
      if (*treePtr == NULL)
      {
         printf("\n%c Cannot be Inserted into the Tree, Because There Are No Memory Available\n");
      }
      else
      {
         //insert Data
         (*treePtr)->data = data;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      }
   }
   else //node is not NULL, insert data to the left/right node
   {
      if (data < (*treePtr)->data) //if data is lower, it will be placed on the left
      {
         insert(&(*treePtr)->leftPtr, data);
      }
      else if (data >= (*treePtr)->data) //if data is lower, it will be placed on the right
      {
         insert(&(*treePtr)->rightPtr, data);
      }
   }
}

//used to push or enqueue the queue of nodePtr
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr data)
{
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

//used to pop or dequeue from the queue of nodePtr
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
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

void printByLevel(TreeNodePtr treePtr)
{
   int depth = findDepth(treePtr); //find the depth of tree

   int nullNode = 0, level = 0;
   //nullNode is used to break the loop when it dequeue two consecutive NULL nodeptr
   //level is used to describe the current depth

   //initialize queue
   QueueNodePtr headPtr = NULL;
   QueueNodePtr tailPtr = NULL;
   TreeNodePtr current;
   TreeNodePtr tempPtr;

   //create dummy node
   TreeNodePtr zero = malloc(sizeof(TreeNode));
   zero->data = 0;
   zero->leftPtr = NULL;
   zero->rightPtr = NULL;

   //initial enqueue
   enqueue(&headPtr, &tailPtr, treePtr);
   enqueue(&headPtr, &tailPtr, NULL);

   printSpace(findSpace(depth - level)); //print initial space for first root

   while (nullNode < 2) //loop until two consecutive NULL is dequeued
   {
      current = dequeue(&headPtr, &tailPtr);
      //the current node ptr that is dequeued from the queue

      if (current == NULL) //indicate current level is complete
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
      else //enequeue the left and right ptr of current node
      {
         nullNode = 0;
         if (current->leftPtr != NULL)
         {
            enqueue(&headPtr, &tailPtr, current->leftPtr);
         }
         else if (depth - level > 0)
         { //add dummy node ptr to fill the spaces
            enqueue(&headPtr, &tailPtr, zero);
         }
         if (current->rightPtr != NULL)
         {
            enqueue(&headPtr, &tailPtr, current->rightPtr);
         }
         else if (depth - level > 0)
         { //add dummy node ptr to fill the spaces
            enqueue(&headPtr, &tailPtr, zero);
         }
         if (current->data != 0)
         {
            printf("%d", current->data);
            //print data
            printSpace(findSpace(depth - level + 1));
            //print enough space
         }
         else
         {
            printSpace(findSpace(depth - level + 1) + 1);
            //print enough space
         }
      }
   }
}

//findDepth function is used to find the depth of the tree, return how many levels
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

int findSpace(int n)
{
   //find appropriate space based on the pattern
   return ((power(2, n) - 1));
}

int power(int num, int x)
{ //power function
   int i;
   int total = 1;
   for (i = 0; i < x; i++)
   {
      total = total * num;
   }
   return total;
}

//print spaces
void printSpace(int amount)
{
   int i;
   for (i = 0; i < amount; i++)
   {
      printf(" ");
   }
}

void traverseInOrder(TreeNodePtr treePtr)
{
   if (treePtr != NULL)
   {
      //Inorder (Left, Root, Right)
      traverseInOrder(treePtr->leftPtr);
      printf("%d  ", treePtr->data);
      traverseInOrder(treePtr->rightPtr);
   }
}
