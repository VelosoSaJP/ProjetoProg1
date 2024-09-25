/*
 A cadastra imagem vai fazer todo o tratamento de cadastrar a imagem, tanto física quanto suas infos 
 */

#include "libTrabalho.h"
int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]){
   // tem que chamar a verfificaExistencia... pra ver se tem no diretório
   Imagem img;
   
   if(!verificaExistenciaDeImagem(nomeImagem)){
      
      return -1;
   }
   
   if(verificaCadastro(arqFisicoImagensBase,nomeImagem)==1){
      //printf("\nImagem já cadastrada!Erro cadastraIMagem");
      return 1;

   }   
   
   //Cadastrando a imagem FÍSICAS
   copiaString(nomeImagem,img.nome);
   img.dimensao.largura=getDimension(nomeImagem,&img.dimensao.altura);
   img.size=getSize(nomeImagem);
   img.id=getLastId(arqFisicoImagensBase)+1;
   getExtension(nomeImagem,img.tipo);
   printf("Quem eh o proprietario?\n");
   scanf("%s",img.proprietario);

   //Para pegar/usar data do sistema
   //descomentar código a seguir
   struct tm tm =getSystemTime();
   img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
   img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
   img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
   
   //Cadastrando as INFORMAÇÕES da imagem no .bin
   gravaInfoImagem(arqFisicoImagensBase,img);
 
   return 0;
}
