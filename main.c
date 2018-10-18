/*
  Trabalho Avaliativo - Estrutura de dados 1 - UFPR
  Equipe: Diego Lemos e Jean de Jesus
  Projeto Fila
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista_Encadeada
{
     int expressao;
     struct Lista_Encadeada *prox;
}pilha;

// Método que inicializa a lista
void inicializa_lista(pilha *N)
  {
    N = NULL;
  }

// Método que aloca memória para o lista
ListaLinear Cria_lista()
{
  ListaLinear *L ;
  L = (ListaLinear*) malloc(sizeof(ListaLinear));
  if(!L)
  {
    printf("Problema de alocação!");
    exit(0);
  }
  return L ;
}

void menuop();

void insere_inicio_lista(Nodo **N, int dado)
int remove_inicio_lista(Nodo **N, int *dado)

int main ()
{
     ListaLinear *Lista;

     inicializa_lista(&Lista);

     do
     {
         menuop();// apenas mostrar as opções
         setbuf(stdin,NULL);
         scanf("%d", &menu);

        switch(menu)
        {
              case 1:
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
 }

 void menuop(){
   printf("\n1. Transforma uma expressão Infixa em Pósfixa ");
   printf("\n2. Transforma uma expressão Infixa em Préfixa ");
   printf("\n3. Lê uma expressão e informa se a expressão é válida ");
   printf("\n4. Lê uma expressão e informa o resultado da expressão ");
   printf("\n5. Sair do Programa: ");
 }

 void insere_inicio_lista(Nodo **N, int dado)
{
   Nodo *novo;
   novo = Cria_Nodo();
   novo->dado = dado;
   novo->prox = *N;
   *N = novo;
}

int remove_inicio_lista(Nodo **N, int *dado)
{
   Nodo *aux;
   if(*N == NULL) //verifica se a lista está vazia
   return 0;
 else
  {
     *dado = (*N)->dado;
     aux = (*N)->prox;
     free(*N);
     *N = aux;
   }
 return 1;
}

