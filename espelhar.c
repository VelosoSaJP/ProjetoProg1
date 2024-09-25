/*
  É assim que a lena se enxerga no espelho
 */
#include "libTrabalho.h"
void espelhar (int **mat, int lin, int col){
    
    int i,j,pixel;

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col/2; j++)
        {
            pixel = mat[i][j];
            mat[i][j] = mat[i][col - 1 - j];
            mat[i][col - 1 - j] = pixel;
         }
   }

}
