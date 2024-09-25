#include "libTrabalho.h"
/*
 Nessa função a gente grava as infos da img no arquivo binário.
 */
int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img){
   
  FILE *arq = fopen(arqFisicoImagensBase,"a+b");
  
   if(arq==NULL){
      printf("\nERRO ao abrir imagem(grafaInfoImagem)\n");
      return 0;
   }
   //Escreve os dados da imagem no arquivo .bin
   fwrite(&img,sizeof(Imagem),1,arq);

   
   fclose(arq);
   //printf("\nImplementar função gravaInfoImagem.\n");
   return 1;
}
