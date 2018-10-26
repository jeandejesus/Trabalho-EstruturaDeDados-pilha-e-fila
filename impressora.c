#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
// Definição da Estrutura Lista Linear Simplemente Encadeada
  typedef struct Bloco
{
int prioridade;
int ip;
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


void push(Nodo **N, int ip , int prioridade) {
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


int pop(Nodo **N,int *ip, int *prioridade) {
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
void imprime_lista_ecandeada(Nodo *N) {

  Nodo *aux;
  if(N == NULL)
    printf("\n NÃO HÁ ARQUIVOS ");
  else {

    for(aux = N; aux != NULL; aux = aux->prox)

      printf("\n  prioridade %d ip : %d",aux->prioridade, aux->ip);

    }
}


int main(){
  Nodo *FilaEntrada,*Fila0,*Fila1,*Fila2;
  int valor;
  FILE *file;
  int prioridade;
  int  ip;
  int ret=0;
  int identficacao;
  int p,dis=0;
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
    while( (fscanf(file,"%d %d ", &prioridade, &ip))!=EOF ){
        printf("prioridade : %d ,ip :  %d\n", prioridade , ip);
        push(&FilaEntrada,ip,prioridade);
      }
  printf("aberto com sucesso\n");
}

  imprime_lista_ecandeada(FilaEntrada);

  while (  pop(&FilaEntrada,&identficacao,&p) != 0) {

    for(int i=0 ; i<5 ; i++){
    pop(&FilaEntrada,&identficacao,&p);sleep(5);

    if (p ==1 ) {
      push(&Fila0,identficacao,p);

    }else if(p==2){
      push(&Fila1,identficacao,p);
    }else if(p==3){
      push(&Fila2,identficacao,p);


          printf("\n-FILA 0 - Prioridade maxima \n" );

          imprime_lista_ecandeada(Fila0);

          printf("\nFILA 1 - Prioridade normal \n" );

          imprime_lista_ecandeada(Fila1);
          printf("\nFILA 2 - Prioridade baixa \n" );

          imprime_lista_ecandeada(Fila2);
    }
  }
  }


    printf("\nEntra :" );
    imprime_lista_ecandeada(FilaEntrada);



    fclose(file);
    free(FilaEntrada);
}
