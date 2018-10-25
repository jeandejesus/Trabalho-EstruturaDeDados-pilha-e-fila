#include<stdio.h>
#include<stdlib.h>

// Definição da Estrutura Lista Linear Simplemente Encadeada
  typedef struct Bloco
{
char ip;
int prioridade;
struct Bloco *prox;
} Nodo;

void inicializa_lista(Nodo **N)//inicializa a lista
{
*N = NULL;
}


Nodo * Cria_Nodo() //aloca memória para o nodo
{
  Nodo *p;
  p = (Nodo *) malloc(sizeof(Nodo));
  if(!p) {
    printf("Problema de alocação");
    exit(0);
  }
return p;
}


void insere_fim_lista(Nodo **N, char ip , int prioridade) {
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


int remove_inicio_lista(Nodo **N,char *ip, int *prioridade) {
  Nodo *aux;
  if(*N == NULL) //verifica se a lista está vazia
    return 0;
    else {
      *ip = (*N)->ip;
      *prioridade = (*N)->prioridade;
      aux = (*N)->prox;
      free(*N);
      *N = aux;
    }
  return 1;
}

int busca_lista(Nodo **N, int *ip ,char *prioridade){
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
void imprime_lista_ecandeada(Nodo *N) {
  printf("entrei na função imprime_lista_ecandeada\n" );
  Nodo *aux;
  if(N == NULL)
    printf("\n A lista está vazia!!");
  else {
    for(aux = N; aux != NULL; aux = aux->prox)
      printf("\n ip : %s prioridade %d ", aux->ip,aux->prioridade);
    }
}


int main(){
  Nodo *FilaEntrada,*Fila0,*Fila1,*Fila2;
  int valor;
  FILE *file;
  int prioridade;
  char  ip[50];

  inicializa_lista(&FilaEntrada);
  inicializa_lista(&Fila0);
  inicializa_lista(&Fila1);
  inicializa_lista(&Fila2);

  file = fopen("Entrada.txt","r");
  if(file == NULL)
  {
    printf("Arquivo não pode ser aberto\n" );
    system("pause");
    return 0 ;
  }else{
    while( (fscanf(file,"%d %s ", &prioridade, ip))!=EOF ){
        printf("prioridade : %d ,ip :  %s\n", prioridade , ip);
        insere_fim_lista(&FilaEntrada,*ip,prioridade);
      }
  printf("aberto com sucesso\n");;
}
  /*while( (fscanf(file,"%d %s ", &prioridade, ip))!=EOF ){
  busca_lista(&FilaEntrada,&ip,&prioridade);
    switch(prioridade) {
        case 1:
            insere_fim_lista(Fila0,ip,prioridade);
          break;
        case 2 :
            insere_fim_lista(Fila1,ip,prioridade);
          break;
        case 3 :
            insere_fim_lista(Fila2,ip,prioridade);
        break;
      return 1;
    }
  }*/

  imprime_lista_ecandeada(FilaEntrada);
    fclose(file);
}
