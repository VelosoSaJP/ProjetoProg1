/*
	Aqui a gente armazena o tipo, altura e largura da imagem
 */
#include "libTrabalho.h"
int getDimension(char nomeImagem[], int *pAltura){

	FILE *arq = fopen(nomeImagem,"r");
		if(arq==NULL){
			printf("\nErro ao abrir arquivo (getDimension)");
			return -1;
		}
	int largura;
	char tipo[3];//É o "P2" que aparece na imagem
	
	fscanf(arq,"%s %d %d",tipo,&largura,pAltura);
	//Le ,nessa ordem, o tipo , largura e altura da imagem que foi dada

	////////////
	//printf("\ndebug %d %d\n",largura,*pAltura);
	//printf("\ndebug nome %s\n",nomeImagem);
	///////////
	fclose(arq);
	return largura;
}
