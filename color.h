typedef struct color
{
   int redPos;
   int greenPos;
   int bluePos;
} Color;

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