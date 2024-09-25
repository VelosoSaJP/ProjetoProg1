/*
 Aqui vou percorrer o vetor nomeImagem até achar um '.' , e depois copio o resto pra pExtension ;)
 */
#include "libTrabalho.h"
void getExtension(char nomeImagem[], char *pExtension){
   
   int i=0 , j=0 ;
   
   while(nomeImagem[i]!='.'){
      i++;
   }
     
   for(j=0;nomeImagem[i]!='\0';j++){ //Uso o nomeImagem como referencia para terminar o loop
      pExtension[j]=nomeImagem[i];
      i++;
   }
   
  pExtension[j]='\0';
  
   //printf("\npExtension %s\n",pExtension);
   //printf("\nnomeImagem %s\n",nomeImagem);
}
