/*
   Nessa parte a gnt verifica se ja esta cadastrado a imagem no arqFisicoIMagem, 
   se nao esta, ent td certo
 */

#include "libTrabalho.h"
int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]){
   
   int cadastrada = 0;
   Imagem img;
   FILE *arq = fopen(arqFisicoImagensBase,"a+b");
  
   if(arq==NULL){
      printf("\nERRO ao abrir imagem(verificaCadastro)\n");
      return -1;
   }

   rewind(arq);

   while (fread(&img,sizeof(Imagem),1,arq)!=0){

      if(comparaStrings(img.nome,nomeImagem)==1){
         //printf("\nJa foi registrada.ERRO verificacadastro\n ");
         fclose(arq);
         return 1;
      }

   }
   
   fclose(arq);
   
   return cadastrada;
   //return 0;
}
