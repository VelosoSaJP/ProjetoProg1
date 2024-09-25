#Neste exemplo de Makefile, os arquivos objetos (.o) são gerados separadamente, assim, somente arquivos fonte (.c) alterados são recompilados para gerar um novo .o. Então o novo .o é linkado com os outros .o (dos arquivos não alterados) para gerar o executável. O make sabe o que deve ser recompilado com base nos timestamps dos arquivos fonte e seus respectivos arquivos objeto.


######### Sintaxe ###########
#regra: dependências
#<TAB>	comando
#############################

#==============
#A regra all: é usada para construir o sistema de forma incremental
all: saida
	@echo " "
	@echo "Compilação concluída , MESTRE!!"
	@echo " "


#==============
#A regra saida: tem como dependências os arquivos objeto, ou seja, para criar o executavel saida precisamos dos 4 arquivos .o
#O comando cria o executável saida a partir dos arquivos objetos progPrincipal.o mult.o soma.o par.o
saida: alocaMatrizImagem.o desalocaMatrizImagem.o getSystemTime.o menuOperacoes.o alocaString.o espelhar.o gravaImagem.o negativo.o alteraImagem.o getDimension.o gravaInfoImagem.o removeImagem.o binarizar.o getExtension.o imprimeImagem.o ruido.o cadastraImagem.o getImage.o leArquivoImagem.o verificaCadastro.o comparaStrings.o getLastId.o listaImagens.o verificaExistenciaDeImagem.o copiaString.o getSize.o main.o
	gcc -o saida alocaMatrizImagem.o desalocaMatrizImagem.o getSystemTime.o menuOperacoes.o alocaString.o espelhar.o gravaImagem.o negativo.o alteraImagem.o getDimension.o gravaInfoImagem.o removeImagem.o binarizar.o getExtension.o imprimeImagem.o ruido.o cadastraImagem.o getImage.o leArquivoImagem.o verificaCadastro.o comparaStrings.o getLastId.o listaImagens.o verificaExistenciaDeImagem.o copiaString.o getSize.o main.o


#==============
#A regra progPrincipal.o: tem como dependência o arquivo fonte, ou seja, para criar progPrincipal.o precisamos do arquivo progPrincipal.c
#O comando cria o arquivo objeto progPrincipal.o a partir do arquivo fonte progPrincipal.c
main.o: main.c
	gcc -o main.o -c main.c

#==============
#A regra mult.o: tem como dependência o arquivo fonte mult.c
#O comando cria o arquivo objeto mult.o a partir do arquivo fonte mult.c

alocaMatrizImagem.o: alocaMatrizImagem.c
	gcc -o alocaMatrizImagem.o -c alocaMatrizImagem.c	

getDimension.o: getDimension.c
	gcc -o getDimension.o -c getDimension.c

leArquivoImagem.o: leArquivoImagem.c
	gcc -o leArquivoImagem.o -c leArquivoImagem.c

alocaString.o: alocaString.c
	gcc -o alocaString.o -c alocaString.c

getExtension.o: getExtension.c
	gcc -o getExtension.o -c getExtension.c

listaImagens.o: listaImagens.c
	gcc -o listaImagens.o -c listaImagens.c

alteraImagem.o: alteraImagem.c
	gcc -o alteraImagem.o -c alteraImagem.c

getImage.o: getImage.c
	gcc -o getImage.o -c getImage.c

binarizar.o: binarizar.c
	gcc -o binarizar.o -c binarizar.c

getLastId.o: getLastId.c
	gcc -o getLastId.o -c getLastId.c

menuOperacoes.o: menuOperacoes.c
	gcc -o menuOperacoes.o -c menuOperacoes.c

cadastraImagem.o: cadastraImagem.c
	gcc -o cadastraImagem.o -c cadastraImagem.c

getSize.o: getSize.c
	gcc -o getSize.o -c getSize.c

comparaStrings.o: comparaStrings.c
	gcc -o comparaStrings.o -c comparaStrings.c		

negativo.o: negativo.c
	gcc -o negativo.o -c negativo.c	

getSystemTime.o: getSystemTime.c
	gcc -o getSystemTime.o -c getSystemTime.c	

removeImagem.o: removeImagem.c
	gcc -o removeImagem.o -c removeImagem.c	

copiaString.o: copiaString.c
	gcc -o copiaString.o -c copiaString.c	

gravaImagem.o: gravaImagem.c
	gcc -o gravaImagem.o -c gravaImagem.c	

ruido.o: ruido.c
	gcc -o ruido.o -c ruido.c	

desalocaMatrizImagem.o: desalocaMatrizImagem.c
	gcc -o desalocaMatrizImagem.o -c desalocaMatrizImagem.c	

espelhar.o: espelhar.c
	gcc -o espelhar.o -c espelhar.c	

gravaInfoImagem.o: gravaInfoImagem.c
	gcc -o gravaInfoImagem.o -c gravaInfoImagem.c	

 imprimeImagem.o: imprimeImagem.c
	gcc -o  imprimeImagem.o -c  imprimeImagem.c	

verificaCadastro.o: verificaCadastro.c
	gcc -o verificaCadastro.o -c verificaCadastro.c	

verificaExistenciaDeImagem.o: verificaExistenciaDeImagem.c
	gcc -o verificaExistenciaDeImagem.o -c verificaExistenciaDeImagem.c	


#==============


#==============
#A regra clean: apaga os arquivos .o ao digitarmos make clean na console
clean:
	rm -f *.o

#==============
#A regra execClean: apaga o arquivo executável ao digitarmos make cleanExec na console
execClean:
	rm -f saida


