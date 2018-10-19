#include<stdio.h>
#include<stdlib.h>

// Definição da Estrutura Lista Linear Simplemente Encadeada
typedef struct Bloco
{
char expressao;
struct Bloco *prox;
} Pilha;

void inicializa_lista(Pilha **N)//inicializa a lista
{
*N = NULL;
}


Pilha * Cria_Pilha() //aloca memória para o Pilha
{
  Pilha *p;
  p = (Pilha *) malloc(sizeof(Pilha));
  if(!p) {
    printf("Problema de alocação");
    exit(0);
  }
return p;
}

void push(Pilha **N, char expressao) {
  Pilha *novo;
  novo = Cria_Pilha();
  novo->expressao = expressao;
  novo->prox = *N;
  *N = novo;
}

int pop(Pilha **N, char *expressao) {
  Pilha *aux;
  if(*N == NULL) //verifica se a lista está vazia
    return 0;
    else {
      *expressao = (*N)->expressao;
      aux = (*N)->prox;
      free(*N);
      *N = aux;
    }
  return 1;
}


int busca_lista(Pilha **N, char *expressao){
  Pilha *aux;
  if (*N == NULL) {
    return 0;
    printf("Lista vazia !!!\n");
  } else {
    aux = *N;
      while(aux != NULL){
        if (aux->expressao == *expressao)
          return 1;
        else
          aux = aux->prox;
     }
     return 0;
  }
}


void imprime_lista_ecandeada(Pilha *N) {
  Pilha *aux;
  if(N == NULL)
    printf("\n A lista está vazia!!");
  else {
    for(aux = N; aux != NULL; aux = aux->prox)
      printf("\n%d", aux->expressao);
    }
}

char Infixa_Posfixa(char expressao, Pilha *p);
char expressao();
void menuop();
int main ()
{
     Pilha *Lista;
     int menu,n=0;
     inicializa_lista(&Lista);
     char op;

     do
     {
        printf("entre com expressão\n");
          scanf("%s\n", op );
         menuop();// apenas mostrar as opções
         setbuf(stdin,NULL);
         scanf("%d", &menu);


        switch(menu)
        {
              case 1:
                Infixa_Posfixa(op,Lista);
              break;
              case 2 :

              break;
              case 3 :

              break;
              case 4:

              break;
              case 5:
              break;

         }
    }while(menu != 5);
    return 1;
    free(Lista);
 }

 void menuop(){
   printf("\n1. Transforma uma expressão Infixa em Pósfixa ");
   printf("\n2. Transforma uma expressão Infixa em Préfixa ");
   printf("\n3. Lê uma expressão e informa se a expressão é válida ");
   printf("\n4. Lê uma expressão e informa o resultado da expressão ");
   printf("\n5. Sair do Programa: ");
 }

 char Infixa_Posfixa(char expressao, Pilha *p){
   printf("%s\n",expressao);
 }


