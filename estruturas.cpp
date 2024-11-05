/*
	Name: exercicio.cpp
	Author: 2830482321001
	Date: 29/10/24 20:17
	Description: C√≥digo de implementa√ß√£o das seguintes funcionalidades por meio de fun√ß√µes:
	- Lista();
	- Pilha();
	- Fila();
	- BubbleSort();
*/

// bibliotecas que ser„o utilizadas;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structs que ser„oo utilizados; 

typedef struct no{
	int value;
	struct no *prox;
}No;

// Prototipa√ß√£o das Functions;

//Global Functions;

void insertAtStart(No **l, int);
void print(No *l);

//List Functions;

void insertAtEnd(No **l, int);
void insertAtMiddle(No **l, int, int);
void removeNo(No **l, int);

// Fila Functions;

void removeFila(No **list);

// Pilha Functions;

void removePilha(No **list);

// Ordena√ß√£o de Dados;

void generateRandomNumbers(int arr[], int n);
void BubbleSort(int arr[], int n, int *comp, int *shift);
void printArr(int arr[], int n);
void SelectSort(int arr[], int n, int *comp, int *shift);
void compareSortingMethods(int arr[], int n);

int main(){
	
	int option, value, previous, opt, sortOpt,comp=0, shift=0;
	int arr[170000];
	int n = sizeof(arr) / sizeof(arr[0]);
	No *list = NULL;
	
	do {
		printf("\nEscolha a estrutura de dados que deseja utilizar:\n0 - Sair\n1 - Fila\n2 - Lista\n3- Pilha\n4 - Ordenacao de Dados\n");
		scanf("%d", &option);
		
		switch(option){
			case 1: // FILA
				system("cls");
				do {
					printf("\nEscolha o metodo que deseja usar:\n0 - Sair\n1 - Inserir Na Fila\n2 - Remover da Fila\n3 - Imprimir Fila\n");
					scanf("%d", &opt);
					switch(opt){
						case 1: // INSERIR NA FILA
							printf("Digite o valor que deseja inserir: ");
							scanf("%d", &value);
							insertAtStart(&list, value);
							break;
						case 2: // REMOVER DA FILA
							removeFila(&list);
							break;
						case 3: // IMPRIMIR A FILA
							print(list);
							break;
						default:
							if(opt != 0){
								printf("Opcao invalida!");
							}else{
								system("cls");
							}
					} // fim do switch
				}while(opt !=0); // fim do Do;
				break; // fim do caso 1
			case 2: // LISTA
				system("cls");
				do {
					printf("\nEscolha o metodo que deseja usar:\n0 - Sair\n1 - Inserir no Inicio\n2 - Inserir no Meio\n3 - Inserir no Fim\n4 - Remover\n5 - Imprimir Lista\n");
					scanf("%d", &opt);
					switch(opt){
						case 1: // INSERIR NO INICIO
							printf("Digite o valor que deseja inserir: ");
							scanf("%d", &value);
							insertAtStart(&list, value);
							break;
						case 2: // INSERIR NO MEIO
							printf("Digite o valor que deseja inserir e sua referencia: ");
							scanf("%d%d", &value, &previous);
							insertAtMiddle(&list, value, previous);
							break;
						case 3: // INSERIR NO FIM
							printf("Digite o valor que deseja inserir: ");
							scanf("%d", &value);
							insertAtEnd(&list, value);
							break;
						case 4:  // REMOVER VALOR
							printf("Digite o valor que deseja remover: ");
							scanf("%d", &value);
							removeNo(&list, value);
							break;
						case 5: // IMPRIMIR LISTA
							print(list);
							break;
						default:
							if(opt != 0){
								printf("Opcao invalida!");
							}else{
								system("cls");
							}
					}
				}while(opt !=0); // fim do Do;
				break; // fim do caso 2
			case 3: // PILHA
				system("cls");
				do {
					printf("\nEscolha o metodo que deseja usar:\n0 - Sair\n1 - Inserir Na Pilha\n2 - Remover da Pilha\n3 - Imprimir Pilha\n");
					scanf("%d", &opt);
					switch(opt){
						case 1: // INSERIR NA PILHA
							printf("Digite o valor que deseja inserir: ");
							scanf("%d", &value);
							insertAtStart(&list, value);
							break;
						case 2: // REMOVER DA PILHA
							removePilha(&list);
							break;
						case 3: // IMPRIMIR A PILHA
							print(list);
							break;
						default:
							if(opt != 0){
								printf("Opcao invalida!");
							}else{
								system("cls");
							}
					}
				}while(opt !=0);
				break; // fim do caso 3
			case 4: // ORDENACAO DE DADOS
				system("cls");
				do{
					printf("\nEscolha o metodo que deseja usar:\n0- Sair\n1 - Gerar Vetor AleatÛrio\n2 - Imprimir Vetor\n3 - Ordenar Dados do Vetor\n");
					scanf("%d", &opt);
					
					switch(opt){
						case 1: // GERAR VETOR ALEATORIO
							system("cls");
							generateRandomNumbers(arr, n);
							printf("Vetor Gerado com sucesso!\n");
							break;
						case 2: // IMPRIMIR VETOR
							system("cls");
							printf("ARRAY ATUAL: \n\n\n");
							printArr(arr, n);
							break;
						case 3: // ENTRANDO NA ORDENACAO DE DADOS
							printf("Qual mÈtodo vocÍ deseja utilizar?\n1 - Bubble Sort\n2 - Select Sort\n3 - Comparar metodos de ordenacao\n");
							scanf("%d", &sortOpt);
								
							switch(sortOpt){
								case 1: // BUBBLE SORT
									BubbleSort(arr, n, &comp, &shift);
									break;
								case 2: // SELECT SORT
									SelectSort(arr, n, &comp, &shift);
									break;
								case 3: // COMPARAR METODOS DE ORDENACAO
									compareSortingMethods(arr, n);
									break;
								default:
									system("cls");
									printf("Valor invalido");
							}
							break;
						default:
							if(opt != 0){
								printf("Valor invalido!");
							}else{
								system("cls");
							}
					}
				}while(opt != 0);
				break; // fim do caso 4
			default:
				if(option != 0){
					printf("Opcao invalida!");
				}else{
					printf("Obrigado por testar o programa!!");
				}
		}// fim do primeiro switch	
	}while(option != 0);
	
	return 0;
} // Fim da Main;


//Criando as Fun√ß√µes()
//Global Functions;

void insertAtStart(No **list, int value){
	No *newNo = (No*)malloc(sizeof(No));
	if(newNo){
		newNo->value = value; 
		newNo->prox = *list;
		*list = newNo;
		system("cls");
	}else
		printf("Erro ao alocar mem√≥ria!");
} // Fim da InsertAtStart

void print(No *list){
	system("cls");
	printf("\nValores: \n");
	while(list){
		if(list->prox){
			printf(" %d ->", list->value);
			list = list->prox;
		}else {
			printf(" %d -> NULL", list->value);
			list = list->prox;
		}
	}
}

//List Functions;



void insertAtEnd(No **list, int value){
	No *aux, *newNo = (No*)malloc(sizeof(No));
	if(newNo){
		newNo->value = value;
		newNo->prox = NULL;
		
		if(*list == NULL){
			*list = newNo;
		}else {
			aux = *list;
			while(aux->prox){
				aux = aux->prox;
			}
			aux->prox = newNo;
		}
		system("cls");
	}else
		printf("Erro ao alocar mem√≥ria!");
} //Fim da InsertAtEnd

void insertAtMiddle(No **list, int value, int previous){
	No *aux, *newNo = (No*)malloc(sizeof(No));
	
	if(newNo){
		newNo->value = value;
		
		if(*list == NULL){
			newNo->prox = NULL;
			*list = newNo; 
		}else{
			aux = *list;
			while(aux->value != previous && aux->prox){
				aux = aux->prox;
			}
			newNo->prox = aux->prox;
			aux->prox = newNo;
		}
		system("cls");
	}else 
		printf("Erro ao alocar mem√≥ria!");
}

void removeNo(No **list, int value){
	No *aux, *previous;
	aux = *list;
	previous = NULL;
	
	while(aux->value != value && aux != NULL){
		previous = aux;
		aux = aux->prox;
	}
	
	if(aux != NULL){
		if(previous == NULL){
			*list = aux->prox;
		}else{
			previous->prox = aux->prox; 
		}
		free(aux);
	}else{
		printf("Valor n√£o encontrado na lista!");
	}
	
}

//Fila Function;


void removeFila(No **list){
	No *previous,*aux;
	
	aux = *list;
	previous = NULL;
	while(aux->prox && aux != NULL){
		previous = aux;
		aux = aux->prox;
	}
	
	if(aux != NULL){
		if(previous == NULL){
			*list = aux->prox;
		}else{
			previous->prox = aux->prox;
		}
		free(aux);
		printf("Primeiro da fila removido com sucesso!");
	}else {
		printf("A lista est√° vazia!");
	}
}

// Pilha Function;

void removePilha(No **list){
	No *aux = *list;
	
	if(aux == NULL){
		printf("A lista est√° vazia!");
	}else{
		*list = aux->prox;
		free(aux);
	}
}

// Ordena√ß√£o de dados Functions;

void generateRandomNumbers(int arr[], int n){
	srand(time(NULL));
	
	for(int i=0;i<n;i++)
		arr[i] = rand();
}

void BubbleSort(int arr[], int n, int *comp, int *shift){
	int i, j, temp;
	*comp = 0;
	*shift = 0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n - i;j++){
			(*comp)++;
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				(*shift)++;
			}
		}
	}
	printf("\n\nBUBBLE SORT:\n\n\nQuantidade de comparacoes feitas: %d\nQuantidade de trocas feitas: %d\n\n\n", *comp, *shift);
}

void SelectSort(int arr[], int n, int *comp, int *shift){
	int i, j, temp, min;
	*comp = 0;
	*shift = 0;
	for(i=0;i<n-1;i++){
		min = i;
		for(j = i + 1; j < n; j++){
			(*comp)++;
			if(arr[j] < arr[min]) min = j;
		}
		if(min != i){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
			(*shift)++;
		}
	}
	printf("\n\nSELECTION SORT:\n\n\nQuantidade de comparacoes feitas: %d\nQuantidade de trocas feitas: %d\n\n\n", *comp, *shift);
}

void compareSortingMethods(int arr[], int n){
	system("cls");
	int i;
	int bubble_comp = 0, bubble_shift = 0, bubble_efficiency = 0;
	int selection_comp = 0, selection_shift = 0, selection_efficiency = 0;
	
	int bubble_arr[n];
	int selection_arr[n];
	for(i = 0; i < n; i++){
		bubble_arr[i] = arr[i];
		selection_arr[i] = arr[i];
	}
	
	printf("VETOR ANTES DA ORDENACAO: \n\n\n");
	printArr(arr, n);
	
	clock_t start_bubble = clock();
	BubbleSort(bubble_arr, n, &bubble_comp, &bubble_shift);
	clock_t end_bubble = clock();
	
	double time_spent_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
	
	clock_t start_selection = clock();
	SelectSort(selection_arr, n, &selection_comp, &selection_shift);
	clock_t end_selection = clock();
	
	double time_spent_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;
	
	printf("VETOR APOS A ORDENACAO: \n\n\n");
	printArr(bubble_arr, n);
	
	printf("\nTempo gasto no bubble sort: %.2f segundos\nTempo gasto no select: %.2f segundos\n", time_spent_bubble, time_spent_selection);
	
	if(time_spent_bubble > 0){
		double efficiency = ((time_spent_bubble - time_spent_selection) / time_spent_bubble) * 100;
		printf("Select Sort foi: %.2f%% mais eficiente que o Bubble Sort.\n\n", efficiency);
	}else{
		printf("tempo de execuÁ„o È abaixo de zero, n„o È possivel calcular a eficiencia!");
	}
}

void printArr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf(" %d |", arr[i]);
	}
}

