/*
  Alocando uma string e retornando ela
 */
#include "libTrabalho.h"

char *alocaString (int size){
   
   char *st;

   st = (char*)malloc(sizeof(char)*size);
   
   if (st == NULL)
   {
      printf("erro alocastring");//Tratamento da string,pq vai que um dia não exista espaço
                                 //na memória pra alocar uma mísera string
      return NULL;
   }
   
   return st;
}
