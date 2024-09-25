/*
 Nessa daqui a gente vai olhar o arquivo binario. Se ele estiver vazio, cria. E depois manda pra funçao 
 de printar, usando o ponteiro pImg. Se tiver vazio, retorna 0, se tiver alguma coisa, manda 1.
 */
#include"libTrabalho.h"

int listaImagens(char arqFisicoImagensBase[]){
   Imagem img; 	
   Imagem *pImg = &img;
   int retornoFREAD = 0;

   FILE *arq = fopen(arqFisicoImagensBase,"a+b");
      if(arq==NULL){
         printf("\nErro ao abrir arquivo(listaImagens)\n");
      }
   rewind(arq);

   while((retornoFREAD=fread(pImg,sizeof(Imagem),1,arq))!= 0){
      imprimeImagem(*pImg);
   
   }
   
   if(retornoFREAD==0){
        fclose(arq);
        return 0;

   }
    
   fclose(arq);
   return 1;	
}

