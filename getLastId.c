/*
 Nessa função quero retornar o último ID cadastrado para fazer a lista das imagens
 */
#include "libTrabalho.h"
int getLastId(char arqFisicoImagensBase[]){

   int lastId = 0;
   //descomentar as 2 linhas a seguir:
   Imagem img;
   Imagem *pImg;
   pImg=&img;

   FILE *arq = fopen(arqFisicoImagensBase,"rb");

   //printf("\nTentando abrir o arquivo: %s\n", arqFisicoImagensBase);
   if (arq == NULL) {
        printf("\nErro ao abrir o arquivo(getLastId)\n");
        return -1;
    }

    while (fread(pImg, sizeof(Imagem), 1, arq) !=0) {
         pImg->id = lastId ;
        lastId++;
    }

    fclose(arq);

   return (lastId); //Quero que a primeira imagem seja 1 , por isso +1 ;)
}
