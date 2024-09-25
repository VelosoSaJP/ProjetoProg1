/*
 Nessa função eu comparo as strings, sem ver o tamanho delas,
 pq se o tamanho for diferente, obrigatoriamente o campo 'i' vai se diferente de uma da outra.
 (Na verdade eu comparei sim pq elas podem ter tamanhos diferentes mas com o começo igual
  Ex: Lena.pgm & Lena.pgmaaaaa)
 */
#include "libTrabalho.h"

int comparaStrings(char st1[], char str2[]){
  int iguais = 0;	
  int i=0 ;
  int tam1=0 , tam2=0 ;
  // printf("\n%s",st1);
   //printf("\n%s\n",str2);
   //scanf("%d",&i);

  for(i=0;st1[i]!='\0';i++)
    tam1++;
  //No for de cima e de baixo eu comparo o tamanho dos nomes
  for(i=0;str2[i]!='\0';i++)
    tam2++;
  
  if(tam1!=tam2){
    //printf("\nTamanhos de nome nao batem.ERRO\n");
    
    return 0;
  }
  i=0;

  while(st1[i]!='\0'){

    if(st1[i]!=str2[i]){
      //printf("\nNome nao bate com o arquivo existente.\n");
      
      return 0; //à primeira letra errada ja retorna 0 pq ta errado o nome
    }
    i++;
  }
  iguais=1;
  //printf("\nImagens iguais");

  return iguais;  
} 
