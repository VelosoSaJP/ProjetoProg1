/*
 Vamos printar todas as informações do registro de cada imagem :)
 */

#include "libTrabalho.h"
void imprimeImagem(Imagem img){

  Imagem *pImg = &img;

  
   printf("\nNome: %s",pImg->nome);
   printf("\nID: %d",pImg->id);
   printf("\nTipo: %s",pImg->tipo);
   printf("\nSize: %d",pImg->size);
   printf("\nAltura: %d",pImg->dimensao.altura);
   printf("\nLargura: %d",pImg->dimensao.largura);
   printf("\nProprietario: %s",pImg->proprietario);
   printf("\nData criacao: %d / %d / %d",pImg->data_criacao.dia,pImg->data_criacao.mes,pImg->data_criacao.ano);
   printf("\nData modificacao: %d / %d / %d",pImg->data_modificacao.dia,pImg->data_modificacao.mes,pImg->data_modificacao.ano);
   printf("\n//====================//\n");

   //printf("\nImplementar - função cadastraImagem.\n");

   //pImg deve necessariamente ser usado para imprimir as informações da imagem pImg->
   //desomentar a próxima linha
   

}
