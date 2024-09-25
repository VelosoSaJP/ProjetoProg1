/*
   Nessa função, a gente localiza uma imagem com base na sua id, e modifica o proprietário e/ou
   a data. Retorna 0 se não existir a imagem e 1 se tudo der certo 
 */
#include "libTrabalho.h"
int alteraImagem(char arqFisicoImagensBase[], int id){
   //descomentar as 2 próximas linhas
   Imagem img;
   Imagem *pImg; 
   pImg = &img; 
   int achou=0;
   char nome[MAX_NAME];
   struct tm tm =getSystemTime();

   FILE *arq = fopen(arqFisicoImagensBase,"r+b");
      if(arq==NULL){
          printf("\nErro ao abrir o arquivo(alteraImagem)\n");
          return -1;
      }

   while( fread(pImg , sizeof(Imagem), 1 , arq)!=0 && !achou){
      if(pImg->id == id){
         achou=1;
         
         printf("\nDigite o nome do novo proprietario:\n");
         scanf("%s",pImg->proprietario);
         
         pImg->data_modificacao.dia=tm.tm_mday;
         pImg->data_modificacao.mes=tm.tm_mon + 1;
         pImg->data_modificacao.ano=tm.tm_year + 1900;
         
         fseek(arq, (-1)*sizeof(Imagem), SEEK_CUR);
         fwrite(pImg,sizeof(Imagem),1,arq);
      }
   }
   
   fclose(arq);
   
   if(achou==1)

      return 1; //Caso de tudo certo
   else
      return 0; //Caso ele percorra o arquivo e não ache uma id que dê match
}
