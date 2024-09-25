/*
 Nessa função a string1 é copiada para a string2, sem mistério
 */
#include "libTrabalho.h"

void copiaString(char str1[], char str2[]){
  
  int i;

  for(i=0;str1[i]!='\0';i++){
    str2[i]=str1[i];
  }
  str2[i]='\0';
  
  //printf("\ncopia strings precisa ser implementada\n");
}
