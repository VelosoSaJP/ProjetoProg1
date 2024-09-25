/*
   Nessa função a gente aloca uma matriz dinamicamente e retorna ela :)
 */

#include "libTrabalho.h"

int **alocaMatrizImagem (int lin, int col){
   
   int **matriz=(int**)malloc(lin*sizeof(int*));
   for(int i=0;i<lin;i++){
      matriz[i]=(int*)malloc(col*sizeof(int));
   }

   return matriz;
}
