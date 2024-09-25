/*
 A função aqui vai ler a matriz da imagem recebida e vai retornar essa matriz para poder trabalhar 
 com ela nas outras funções
 */
#include "libTrabalho.h"

int **leArquivoImagem (char *nomeArqEntrada, char *tipo, int *lin, int *col, int *maxval){

    int **mat;
    
    int i, j;
    FILE *arq = fopen(nomeArqEntrada, "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo da imagem(leArquivo)");
        return NULL;
    }
   
    fscanf(arq,"%s %d %d %d", tipo, col, lin, maxval);
   
    mat = alocaMatrizImagem (*lin, *col);
    
    for (i = 0; i < *lin; i++)
    {
        for (j = 0; j < *col; j++)
        {
             fscanf(arq,"%d", &mat[i][j] );
        }
    }
    
   fclose(arq); 
      
    return mat;   
}

