/*
   Lena black & white
 */
#include "libTrabalho.h"

void negativo (int **mat, int lin, int col){
   
   int i,j;

   for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mat[i][j] == 255)
            {
                mat[i][j] = 0;
            }
            if(mat[i][j]== 0)
            {
               mat[i][j] = 255;
            }
            else
               mat[i][j] = 255 - mat[i][j]; 
        }
    }

}
