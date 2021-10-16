#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/* Definição da Fila */
typedef struct No {
	int elemento;
	struct No *proximo;
} No;

typedef struct Fila {
	No* inicio;
	No* fim;
	int qtdElementos;
} Fila;

/* Inicia a Fila */
void iniciaFila(Fila *f) {
	f->inicio = NULL;
	f->fim = NULL;
	f->qtdElementos = 0;
}


/* Insere elementos na Fila */
void insereElementos(int num, Fila *f) {
	No *novo_no = (No*)malloc(sizeof(No));
	if(novo_no == NULL) {
		printf("\n\t###### ERRO: Sem memória para inserção do elemento ######\n");
		return;
	} else {
		novo_no->elemento = num;
		novo_no->proximo = NULL;
		if(f->inicio == NULL) { // inserindo no primeiro no
			f->inicio = novo_no;
		} else {
			f->fim->proximo = novo_no;
		}
		// atualiza para um novo no
		f->fim = novo_no;
		f->qtdElementos++;
		return;
	}
}


/* Impressão da Fila */
void imprimiFila(Fila *f) {
	No *novo_no = f->inicio;
	if(novo_no != NULL) {
		while(novo_no != NULL) {
			printf("%d ", novo_no->elemento);
			novo_no = novo_no->proximo;
		}
	} else {
		printf("\n\t###### ATENÇÃO: Fila encontra-se vazia! ######\n", setlocale(LC_ALL, "Portuguese"));
		return;
	}
}

/* Retorna a quantidade dos elementos */
void qtdElementos(Fila *f) {
	printf("\nQuantidade de Elementos na Fila: %d", f->qtdElementos);
	return;
}

/* Busca o elemento e a posição do elemento na Fila */
void buscaElementos(int num, Fila *f) {
	No *aux = f->inicio;
	int contador = 1;
	bool busca = false;
	
	while(aux != NULL && busca == false) {
		if(aux->elemento == num) {
			busca = true;
			printf("\n\t###### ENCONTRADO: Elemento informado na Posição %d", contador);
		} else {
			aux = aux->proximo;
			contador++;
		}
	}
	if(busca == false) {
		printf("\n\t###### ATENÇÃO: Elemento informado não existe na fila ######\n", setlocale(LC_ALL, "Portuguese"));
		return;
	}
}

/* Exluir a Fila */
void excluiFila(Fila *f) {
	if(f->inicio == NULL) {
		printf("\n\t###### ATENÇÃO: Fila encontra-se vazia! ######\n", setlocale(LC_ALL, "Portuguese"));
	} else {
		No *auxiliar;
		auxiliar = f->inicio;
		while(auxiliar != NULL) {
			f->inicio = f->inicio->proximo;
			free(auxiliar);
			auxiliar = f->inicio;
		}
		printf("\n\t###### AVISO: Todos os elementos da fila foram removidos ######\n");
	}
	return;
}

/* Teste das funções criadas */
int main() {
	int opMenu;
    int elementoFila;
    
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	if(fila == NULL) {
		printf("\n\tSem memória para a estrutura de dados!\n");
		exit(-1);
	} else {
		do {
			printf("\n\n\t@@@@@@@@@@@@@@ Trabalho de Estrutura de Dados - Fila @@@@@@@@@@@@@@\n");
			printf("\n0- Encerrar Aplicação", setlocale(LC_ALL, "Portuguese"));
			printf("\n1- Iniciar/Reiniciar Fila");
			printf("\n2- Inserir Elementos");
			printf("\n3- Imprimir a Fila");
			printf("\n4- Números de Elementos na Fila", setlocale(LC_ALL, "Portuguese"));
			printf("\n5- Busca de Elementos na Fila");
			printf("\n6- Excluir a Fila");
			printf("\n\nEscolha uma das opções apresentadas: ", setlocale(LC_ALL, "Portuguese"));
			scanf("%d", &opMenu);

			switch(opMenu) {
				case 0:
					printf("\n\t#####################################\n");
					printf("\t\tAplicação Encerrada!\n");
					printf("\t#########################################");
					break;

				case 1:
					printf("\n\t################################################\n");
					printf("\t\tInicializando/Reiniciando a Fila\n");
					printf("\t####################################################\n");
					iniciaFila(fila);
					break;

				case 2:
					printf("\n\t################################################\n");
					printf("\t\tInserindo Elementos na fila\n");
					printf("\t####################################################\n");
					printf("\nInforme um elemento: ");
					scanf("%d", &elementoFila);
					insereElementos(elementoFila, fila);
					break;

				case 3:
					printf("\n\t####################################\n");
					printf("\t\tImprimindo a Fila\n");
					printf("\t########################################\n");
					imprimiFila(fila);
					break;
					
				case 4:
					printf("\n\t###############################################################\n");
					printf("\t\tApresentando a Quantidade/Números de Elementos na Fila\n", setlocale(LC_ALL, "Portuguese"));
					printf("\t###################################################################\n");
					qtdElementos(fila);
					break;
					
				case 5:
					printf("\n\t##########################################\n");
					printf("\t\tBusca de Elementos na Fila\n");
					printf("\t##############################################\n");
					printf("\nInforme um elemento: ");
					scanf("%d", &elementoFila);
					buscaElementos(elementoFila, fila);
					break;
				
				case 6:
					printf("\n\t####################################\n");
					printf("\t\tExluindo a Fila\n");
					printf("\t########################################\n");
					excluiFila(fila);
					break;

				default:
					printf("\n\t################################\n");
					printf("\t\tOpção Inválida!\n", setlocale(LC_ALL, "Portuguese"));
					printf("\t#####################################\n");
					break;
			}

		} while(opMenu != 0);
	}
}
