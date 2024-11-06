/*
	Name: exercicio.cpp
	Author: 2830482321001
	Date: 29/10/24 20:17
	Description: Código de implementação das seguintes funcionalidades por meio de funções:
	- Lista();
	- Pilha();
	- Fila();
	- BubbleSort();
*/

// bibliotecas que ser�o utilizadas;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structs que ser�oo utilizados; 

typedef struct no{
	int value;
	struct no *prox;
}No;

// Prototipação das Functions;

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

// Ordenação de Dados;

void generateRandomNumbers(int arr[], int n);
void BubbleSort(int arr[], int n, int *comp, int *shift);
void printArr(int arr[], int n);
void SelectSort(int arr[], int n, int *comp, int *shift);
void compareSortingMethods(int arr[], int n);
void InsertionSort(int arr[], int n, int *comp, int *shift);
void ShellSort(int arr[], int n, int *comp, int *shift);

int main(){
	
	int option, value, previous, opt, sortOpt,comp=0, shift=0;
	int arr[100000];
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
					printf("\nEscolha o metodo que deseja usar:\n0- Sair\n1 - Gerar Vetor Aleat�rio\n2 - Imprimir Vetor\n3 - Ordenar Dados do Vetor\n");
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
							printf("Qual m�todo voc� deseja utilizar?\n1 - Bubble Sort\n2 - Select Sort\n3 - Insertion Sort\n4 - Shell Sort\n5 - Comparar metodos de ordenacao\n");
							scanf("%d", &sortOpt);
								
							switch(sortOpt){
								case 1: // BUBBLE SORT
									BubbleSort(arr, n, &comp, &shift);
									break;
								case 2: // SELECT SORT
									SelectSort(arr, n, &comp, &shift);
									break;
								case 3:
									InsertionSort(arr, n, &comp, &shift);
									break;
								case 4:
									ShellSort(arr, n, &comp, &shift);
									break;
								case 5: // COMPARAR METODOS DE ORDENACAO
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


//Criando as Funções()
//Global Functions;

void insertAtStart(No **list, int value){
	No *newNo = (No*)malloc(sizeof(No));
	if(newNo){
		newNo->value = value; 
		newNo->prox = *list;
		*list = newNo;
		system("cls");
	}else
		printf("Erro ao alocar memória!");
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
		printf("Erro ao alocar memória!");
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
		printf("Erro ao alocar memória!");
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
		printf("Valor não encontrado na lista!");
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
		printf("A lista está vazia!");
	}
}

// Pilha Function;

void removePilha(No **list){
	No *aux = *list;
	
	if(aux == NULL){
		printf("A lista está vazia!");
	}else{
		*list = aux->prox;
		free(aux);
	}
}

// Ordenação de dados Functions;

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

void InsertionSort(int arr[], int n, int *comp, int *shift){
	int i = 0, j = 0, key = 0;
	
	for(i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		(*comp)++;
		while(j >= 0 && arr[j] > key){
			(*shift)++;
			(*comp)++;
			arr[j + 1] = arr[j];
			j--;			
		}
		arr[j+1] = key;
	}
	printf("\n");
}

void ShellSort(int arr[], int n, int *comp, int *shift){
	int i,j, value;
	
	int h = 1;
	while(h < n){
		h = 3*h+1;
	}
	while(h > 0){
		for(i = h; i < n; i++){
			value = arr[i];
			j = i;
			while(j > h-1 && value <= arr[j - h]){
				arr[j] = arr [j - h];
				j = j - h;
			}
			arr[j] = value;
		}
		h = h/3;
	}
}

void compareSortingMethods(int arr[], int n){
	system("cls");
	int i, choose, c;
	int first_comp = 0, first_shift = 0, second_comp = 0, second_shift = 0, third_comp = 0, third_shift = 0, fourth_comp = 0, fourth_shift = 0, first_arr[n], second_arr[n], third_arr[n], fourth_arr[n];
	clock_t first_start, second_start, third_start, fourth_start, first_end, second_end, third_end, fourth_end;
	double time_first = 0, time_second = 0, time_third = 0, time_fourth = 0;
	
	printf("Escolha qual m�todo deseja comparar: \n1 - Bubble Sort\n2 - Select Sort\n3 - Insertion Sort\n4 - Shell Sort\n5 - Comparar todos\n");
	scanf("%d", &choose);
	switch(choose){
		case 1:
			printf("Deseja comparar o Bubble com quem?\n1 - Select Sort\n2 - Insertion Sort\n3 - Shell Sort\n");
			scanf("%d", &c);
			switch(c){
				case 1:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					BubbleSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					SelectSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no bubble sort: %.2f segundos\nTempo gasto no select: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O select sort foi: %.2f%% mais eficiente que o bubble sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O bubble sort foi: %.2f%% mais eficiente que o select sort.", efficiency);
					}
					break;
				case 2:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					BubbleSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					InsertionSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no bubble sort: %.2f segundos\nTempo gasto no insertion: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O insertion sort foi: %.2f%% mais eficiente que o bubble sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O bubble sort foi: %.2f%% mais eficiente que o insertion sort.", efficiency);
					}
					break;
				case 3:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					BubbleSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					ShellSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no bubble sort: %.2f segundos\nTempo gasto no shell: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O shell sort foi: %.2f%% mais eficiente que o bubble sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O bubble sort foi: %.2f%% mais eficiente que o shell sort.", efficiency);
					}
					break;
			}
			break;
		case 2:
			printf("Deseja comparar o Select com quem?\n1 - Bubble Sort\n2 - Insertion Sort\n3 - Shell Sort\n");
			scanf("%d", &c);
			switch(c){
				case 1:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					SelectSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					BubbleSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no select sort: %.2f segundos\nTempo gasto no bubble: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Bubble sort foi: %.2f%% mais eficiente que o Select sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Select sort foi: %.2f%% mais eficiente que o Bubble sort.", efficiency);
					}
					break;
				case 2:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					SelectSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					InsertionSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no select sort: %.2f segundos\nTempo gasto no insertion: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O insertion sort foi: %.2f%% mais eficiente que o Select sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O select sort foi: %.2f%% mais eficiente que o insertion sort.", efficiency);
					}
					break;
				case 3:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					SelectSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					ShellSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no select sort: %.2f segundos\nTempo gasto no shell: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Shell sort foi: %.2f%% mais eficiente que o Select sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Select sort foi: %.2f%% mais eficiente que o Shell sort.", efficiency);
					}
					break;
			}
			break;
		case 3:
			printf("Deseja comparar o Insertion com quem?\n1 - Bubble Sort\n2 - Select Sort\n3 - Shell Sort\n");
			scanf("%d", &c);
			switch(c){
				case 1:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					InsertionSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					BubbleSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no Insertion sort: %.2f segundos\nTempo gasto no Bubble: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Bubble sort foi: %.2f%% mais eficiente que o Insertion sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Insertion sort foi: %.2f%% mais eficiente que o Bubble sort.", efficiency);
					}
					break;
				case 2:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					InsertionSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					SelectSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no Insertion sort: %.2f segundos\nTempo gasto no Select Sort: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Select sort foi: %.2f%% mais eficiente que o Insertion sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Insertion sort foi: %.2f%% mais eficiente que o Select sort.", efficiency);
					}
					break;
				case 3:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					InsertionSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					ShellSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no Insertion sort: %.2f segundos\nTempo gasto no Shell Sort: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Shell sort foi: %.2f%% mais eficiente que o Insertion sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Insertion sort foi: %.2f%% mais eficiente que o Shell sort.", efficiency);
					}
					break;
			}
			break;
		case 4:
			printf("Deseja comparar o Shell com quem?\n1 - Bubble Sort\n2 - Select Sort\n3 - Insertion Sort\n");
			scanf("%d", &c);
			switch(c){
				case 1:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					ShellSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					BubbleSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no Shell sort: %.2f segundos\nTempo gasto no Bubble sort: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Bubble sort foi: %.2f%% mais eficiente que o Shell sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Shell sort foi: %.2f%% mais eficiente que o Bubble sort.", efficiency);
					}
					break;
				case 2:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					ShellSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					SelectSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no Shell sort: %.2f segundos\nTempo gasto no Select sort: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Select sort foi: %.2f%% mais eficiente que o Shell sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Shell sort foi: %.2f%% mais eficiente que o Select sort.", efficiency);
					}
					break;
				case 3:
					for(i = 0; i < n; i++){
						first_arr[i] = arr[i];
						second_arr[i] = arr[i];
					}
					
					printf("VETOR ANTES DA ORDENACAO: \n\n\n");
					printArr(arr, n);
					
					first_start = clock();
					ShellSort(first_arr, n, &first_comp, &first_shift);
					first_end = clock();
					
					time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
					
					second_start = clock();
					InsertionSort(second_arr, n, &second_comp, &second_shift);
					second_end = clock();
					
					time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
					
					printf("VETOR APOS A ORDENACAO: \n\n\n");
					printArr(first_arr, n);
					
					printf("\nTempo gasto no Shell sort: %.2f segundos\nTempo gasto no Insertion sort: %.2f segundos\n", time_first, time_second);
					
					if(time_second < time_first){
						double efficiency = ((time_first / time_second) - 1) * 100;
						printf("O Insertion sort foi: %.2f%% mais eficiente que o Shell sort.", efficiency);
					}else{
						double efficiency = ((time_second / time_first) - 1) * 100;
						printf("O Shell sort foi: %.2f%% mais eficiente que o Insertion sort.", efficiency);
					}
					break;
			}
			break;
		case 5:
			for(i = 0; i < n; i++){
				first_arr[i] = arr[i];
				second_arr[i] = arr[i];
				third_arr[i] = arr[i];
				fourth_arr[i] = arr[i];
			}
			
			printf("VETOR DESORDENADO: \n\n\n");
			printArr(arr, n);
			
			first_start = clock();
			BubbleSort(first_arr, n, &first_comp, &first_shift);
			first_end = clock();
			
			time_first = (double)(first_end - first_start) / CLOCKS_PER_SEC;
			
			second_start = clock();
			SelectSort(second_arr, n, &second_comp, &second_shift);
			second_end = clock();
			
			time_second = (double)(second_end - second_start) / CLOCKS_PER_SEC;
			
			third_start = clock();
			InsertionSort(third_arr, n, &third_comp, &third_shift);
			third_end = clock();
			
			time_third = (double)(third_end - third_start) / CLOCKS_PER_SEC;
			
			fourth_start = clock();
			ShellSort(fourth_arr, n, &fourth_comp, &fourth_shift);
			fourth_end = clock();
			
			time_fourth = (double)(fourth_end - fourth_start) / CLOCKS_PER_SEC;
			
			printf("\nTempo gasto no bubble sort: %.4f segundos\nTempo gasto no select sort: %.4f segundos\nTempo gasto no insertion sort: %.4f segundos\nTempo gasto no shell sort: %.4f segundos\n", time_first, time_second, time_third, time_fourth);
		default:
			break;
	}
	
	
}

void printArr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf(" %d |", arr[i]);
	}
}

