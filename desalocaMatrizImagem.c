/*
 Aqui nessa função a gente desaloca a matriz que tinha sido alocada dinamicamente :)
 */
#include "libTrabalho.h"
void desalocaMatrizImagem(int **mat, int lin, int col){

   for(int i=0 ; i<col ; i++){
      free(mat[i]);
   }
   free(mat);
}
