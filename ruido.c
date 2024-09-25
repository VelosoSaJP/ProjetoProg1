/*
   A lena vai ficar com ruido agora
 */
#include "libTrabalho.h"

void ruido (int **mat, int lin, int col){
  
    int i,j;
    srand(time(NULL));
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
         mat[i][j]+=rand()%100;
         if(mat[i][j]>255)//caso o ruido deixe o valor do pixel maior que 255
            mat[i][j]=255;
         }
   }
}