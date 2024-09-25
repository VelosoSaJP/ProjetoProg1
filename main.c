// libTrabalho.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos.
#include "libTrabalho.h"

int main()
{

	//=======Variáveis para cadastro na base
	// arqFisicoImagensBase.txt armazena todas as informações sobre as imagens cadastradas.
	char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
	int id;
	char nomeImagem[MAX_NAME];

	//======Variáveis para operações sobre imagens
	int opt = 1, lin, col, maxval, gravou;
	char *tipo, *nomeArqSaida;
	int **matImagem;
	char *auxNomeImagem;
	Imagem img;

	struct tm tm = getSystemTime();

	//=========Minhas variáveis===================================//
	int retornoLista, retornoAlteraImg, retornoGravaImagem,resultado;

	do
	{
		// Função que mostra as opções para o usuário ao executar o programa
		menuOperacoes();
		scanf("%d", &opt);

		switch (opt)
		{
		case 0:
			printf("\nSaindo...\n");
			break;

		case 1: // listaImagens
			retornoLista = listaImagens(arqFisicoImagensBase);

			if (retornoLista == 0)
			{
				printf("\nRegistro de imagens vazio\n");
			}

			break;

		case 2:
			// cadastraImagem

			printf("\nNome da imagem a cadastrar: ");
			scanf("%s", nomeImagem);
			resultado = cadastraImagem(arqFisicoImagensBase, nomeImagem);
			if (resultado == 0)
			{
				printf("\nImagem cadastrada com sucesso!\n");
			}
			else if (resultado == 1)
			{
				printf("\nImagem já cadastrada\n");
			}
			else
				printf("\nErro ao cadastrar imagem, não existe no diretório\n");

			break;

		case 3:
			//===alteraImagem

			printf("\nDigite o ID da imagem a ser alterada:\n");
			scanf("%d", &id);

			retornoAlteraImg = alteraImagem(arqFisicoImagensBase, id);

			if (retornoAlteraImg == 0)
				printf("\nErro! Imagem nao cadastrada\n");
			if (retornoAlteraImg == 1)
				printf("\nImagem alterada com sucesso!\n");

			break;

		case 4:
			//===removeImagem
			printf("\nID da imagem a remover: ");
			scanf("%d", &id);
			removeImagem(arqFisicoImagensBase, id);
			break;

		case 5: // binarizar(matImagem, lin, col);
			//===Binarizar
			
			tipo = alocaString(MAX_NAME);

			auxNomeImagem = alocaString(MAX_NAME);
			if (auxNomeImagem == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			nomeArqSaida = alocaString(MAX_NAME);
			if (nomeArqSaida == NULL)
			{
				printf("\nAloca sling retornou NULL ERRO\n");
				break;
			}

			do
			{
				printf("\nDigite o nome da imagem a ser binarizada:\n");
				scanf("%s", auxNomeImagem);
			} while (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) == 0);


			
			
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			
			if (matImagem == NULL)
			{
				printf("\nmatIMagem recebeu -1 ERRO\n");
				break;
			}
			//=====================BINARIZA=======================================//
			binarizar(matImagem, lin, col);
			//=====================BINARIZA=======================================//

			do
			{
				printf("\nDigite o nome da nova imagem:\n");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) == 1);

			retornoGravaImagem=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(retornoGravaImagem==1){
				printf("\nErro na gravaImagem\n");
				break;
			}
			
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			copiaString(nomeArqSaida, img.nome);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			tm = getSystemTime();
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			
			gravaInfoImagem(arqFisicoImagensBase, img);
			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);
			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			desalocaMatrizImagem(matImagem, lin, col);
			free(nomeArqSaida);
			free(tipo);
			break;

		case 6: // ruido(matImagem, lin, col);
			//===Ruído

			tipo = alocaString(MAX_NAME);

			auxNomeImagem = alocaString(MAX_NAME);
			if (auxNomeImagem == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			nomeArqSaida = alocaString(MAX_NAME);
			if (nomeArqSaida == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			do
			{
				printf("\nDigite o nome da imagem a ser binarizada:\n");
				scanf("%s", auxNomeImagem);
			} while (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) == 0);


			
			
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			
			if (matImagem == NULL)
			{
				printf("\nmatImagem recebeu -1 ERRO\n");
				break;
			}
			//=====================RUIDO=======================================//
			ruido(matImagem, lin, col);
			//=====================RUIDO=======================================//

			do
			{
				printf("\nDigite o nome da nova imagem:\n");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) == 1);

			retornoGravaImagem=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(retornoGravaImagem==1){
				printf("\nErro na gravaImagem\n");
				break;
			}

			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			copiaString(nomeArqSaida, img.nome);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			tm = getSystemTime();
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			gravaInfoImagem(arqFisicoImagensBase, img);
			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			desalocaMatrizImagem(matImagem, lin, col);
			free(nomeArqSaida);
			free(tipo);

			break;

		case 7: // negativo(matImagem, lin, col);
			//===Negativo

tipo = alocaString(MAX_NAME);

			auxNomeImagem = alocaString(MAX_NAME);
			if (auxNomeImagem == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			nomeArqSaida = alocaString(MAX_NAME);
			if (nomeArqSaida == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			do
			{
				printf("\nDigite o nome da imagem a ser binarizada:\n");
				scanf("%s", auxNomeImagem);
			} while (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) == 0);


			
			
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			
			if (matImagem == NULL)
			{
				printf("\nmatImagem recebeu -1 ERRO\n");
				break;
			}
			//=====================NEGATIVO=======================================//
			negativo(matImagem, lin, col);
			//=====================NEGATIVO=======================================//

			do
			{
				printf("\nDigite o nome da nova imagem:\n");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) == 1);

			retornoGravaImagem=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(retornoGravaImagem==1){
				printf("\nErro na gravaImagem\n");
				break;
			}

			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			copiaString(nomeArqSaida, img.nome);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			tm = getSystemTime();
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			gravaInfoImagem(arqFisicoImagensBase, img);
			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			desalocaMatrizImagem(matImagem, lin, col);
			free(nomeArqSaida);
			free(tipo);

			break;

		case 8: // espelhar(matImagem, lin, col);
			//====Espelhamento

tipo = alocaString(MAX_NAME);

			auxNomeImagem = alocaString(MAX_NAME);
			if (auxNomeImagem == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			nomeArqSaida = alocaString(MAX_NAME);
			if (nomeArqSaida == NULL)
			{
				printf("\nAloca sling retornou NULL\n");
				break;
			}

			do
			{
				printf("\nDigite o nome da imagem a ser binarizada:\n");
				scanf("%s", auxNomeImagem);
			} while (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) == 0);


			
			
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			
			if (matImagem == NULL)
			{
				printf("\nmatImagem recebeu -1 ERRO\n");
				break;
			}
			//=====================ESPELHA=======================================//
			espelhar(matImagem, lin, col);
			//=====================ESPELHA=======================================//

			do
			{
				printf("\nDigite o nome da nova imagem:\n");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) == 1);

			retornoGravaImagem=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(retornoGravaImagem==1){
				printf("\nErro na gravaImagem\n");
				break;
			}

			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			copiaString(nomeArqSaida, img.nome);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			tm = getSystemTime();
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			gravaInfoImagem(arqFisicoImagensBase, img);
			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			cadastraImagem(arqFisicoImagensBase, nomeArqSaida);

			desalocaMatrizImagem(matImagem, lin, col);
			free(nomeArqSaida);
			free(tipo);

			break;
		default:
			printf("\nOpção inválida");
		}

	} while (opt != 0);

	return 0;
}
