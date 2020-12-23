//Struct
typedef struct color
{ /*the struct is used to reduce the amount of parameter needed*/
   int redPos;
   int greenPos;
   int bluePos;
} Color;

/*function to add color into a certain index in the visualized array*/
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