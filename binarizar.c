/*
 Vamo binarizar a lena :)
 */
#include "libTrabalho.h"

void binarizar (int **mat, int lin, int col){

    int i,j;
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mat[i][j] <= 127)
            {
                mat[i][j] = 0;
            }
            else
                mat[i][j] = 255;
        }
    }
}
