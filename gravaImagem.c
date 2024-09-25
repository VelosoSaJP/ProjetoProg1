/*
  Essa função auqi vai salvar como arquivo a imagem depois de ser binarizada,espelhada...
 */
#include "libTrabalho.h"

int gravaImagem (char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat){
   
   int i,j;

   FILE *arq = fopen(nomeArqSaida,"w");
      if(arq==NULL){
         printf("\nErro na gravaImagem\n");
         return 1;
      }

      fprintf(arq,"%s\n%d %d\n%d\n",tipo,lin,col,maxval);

      for(i=0;i<lin;i++){
         for(j=0;j<col;j++){

            fprintf(arq,"%d ",mat[i][j]);

         }
         fprintf(arq,"\n");
      }
   
   return 0;
}
