
// Inclusão das bibliotecas necessárias
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>

// Definição da Estrutura Lista Linear Simplemente Encadeada
typedef struct Bloco
{
  int prioridade;
  int ip;
  struct Bloco *prox;
} Nodo;

// Inicializa a lista
void inicializa_lista(Nodo **N)
{
  *N = NULL;
}

// Aloca memória para o nodo
Nodo * Cria_Nodo()
{
  Nodo *p;
  p = (Nodo *) malloc(sizeof(Nodo));
  if(!p) {
    printf("Problema de alocação");
    exit(0);
  }
return p;
}

// Função que insere no fim da fila
void insere_fim(Nodo **N, int ip , int prioridade) {
  Nodo *novo, * aux, * aux2;
  novo = Cria_Nodo( );
  novo->ip = ip;
  novo->prioridade = prioridade;
  novo->prox = NULL;
    if(*N == NULL)
      *N = novo;
        else {
          aux = *N;
          while(aux->prox != NULL)
            aux = aux->prox;
            aux->prox = novo;
        }
}

// Remove do fim da fila
int remove_inicio(Nodo **N,int *ip, int *prioridade) {
  Nodo *aux;
  if(*N == NULL) //verifica se a lista está vazia
    return 0;
    else {

     *prioridade = (*N)->prioridade;
     *ip = (*N)->ip;
      aux = (*N)->prox;
      free(*N);
      *N = aux;
    }
  return 1;
}

// Função que busca na lista
int busca_lista(Nodo **N, char *ip ,int *prioridade){
  Nodo *aux;
  if (*N == NULL) {
    return 0;
    printf("Lista vazia !!!\n");
  } else {
    aux = *N;
      while(aux != NULL){
        if (aux->ip == *ip && aux->prioridade == *prioridade)
          return 1;
        else
          aux = aux->prox;
     }
     return 0;
  }
}

// Função que imprima a lista
void imprime_fila(Nodo *N) {

  Nodo *aux;
  if(N == NULL)
    printf("\n\t NÃO HÁ ARQUIVOS ");
  else {
    for(aux = N; aux != NULL; aux = aux->prox){
      printf("\n\t  prioridade %d ip : %d",aux->prioridade, aux->ip);
    }
  }
}

void menu();
void distribuir(Nodo **FilaEntrada);
void limpalista(Nodo **lista);
int main()
{
  Nodo *FilaEntrada;
  FILE *file;
  int prioridade;
  int ip, totSolicitacoes=0;
  char ch;
  inicializa_lista(&FilaEntrada);
  menu();
  file = fopen("Entrada.txt","r");
  if(file == NULL)
  {
    printf("Arquivo não pode ser aberto\n" );
    system("pause");
    return 0;
  }else{
        while( (ch=fgetc(file))!= EOF ){
        if(ch == '\n')
        totSolicitacoes++;
      }

      if (totSolicitacoes >=50) {
        rewind(file);
        while( (fscanf(file,"%d %d ", &prioridade, &ip))!=EOF )
        {
          printf("\tprioridade : %d ,ip :  %d\n", prioridade , ip);
          insere_fim(&FilaEntrada,ip,prioridade);
        }
        printf("\tPreparando fila de impressão..\n");
        distribuir(&FilaEntrada);
        printf("\n\t lista de Entrada :" );
        imprime_fila(FilaEntrada);
        fclose(file);
        limpalista(&FilaEntrada);
      } else if (totSolicitacoes < 50){
        printf("\tO arquivo precisa de no mínimo 50 solitações para realizar a impressão!\n");
      }
  }
}

void menu() {
  printf("\t----------------\n");
  printf("\t IMPRESSORA\n");
  printf("\t----------------\n");
}
// Função que distribui da fila principal para as filas de prioridade
void distribuir(Nodo **FilaEntrada) {

  int identificacao,p,x,i=0,j=0;
  Nodo *Fila1,*Fila2,*Fila3;
  inicializa_lista(&Fila1);
  inicializa_lista(&Fila2);
  inicializa_lista(&Fila3);
  while (*FilaEntrada != NULL ) {

    for(i=0;i<5;i++){
        if (*FilaEntrada == NULL) {
          break;
        }else{
          remove_inicio(FilaEntrada,&identificacao,&p);
          sleep(1);
          /*
           Se prioridade foi 1- Insere na fila 0
           Se prioridade foi 2- Insere na fila 1
           Se prioridade foi 3- Insere na fila 2
           */
          if (p ==1 ) {
            insere_fim(&Fila1,identificacao,p);
          }else if(p==2){
            insere_fim(&Fila2,identificacao,p);
          }else if(p==3){
            insere_fim(&Fila3,identificacao,p);
          }
          j++;
        }
    }

    printf("\n\n\n\t [ FILA DE IMPRESSÃO ]  \n\n\n  " );
    printf("\n\n\tFILA 1 - Prioridade máxima \n" );
    imprime_fila(Fila1);
    printf("\n\n\tFILA 2 - Prioridade normal \n\n" );
    imprime_fila(Fila2);
    printf("\n\n\tFILA 3 - Prioridade baixa \n\n" );
    imprime_fila(Fila3);
    printf("\n\n\t---------------------------- \n\n  " );
    printf("\n\n\t Quantidade em espera = %d\n",j );
  }
    printf("\t FIM\n" );
}

// Função que vai em cada nó e libera a memória alocada
void limpalista(Nodo **lista)
{
	Nodo *p;
  printf("\n\t---Liberando lista-----");
	if(*lista == NULL)
	{
		printf("\n\tLista Vazia\n");
	}
	else
	{
		while(*lista!=NULL)
		{
			p = *lista;
			*lista = (*lista)->prox;
			free(p);
		}
	}
}
