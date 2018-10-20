#include<stdio.h>
#include<stdlib.h>
// Definição da Estrutura Lista Linear Simplemente Encadeada
typedef struct Bloco
{
char dado;
struct Bloco *prox;
}   Pilha;

void inicializa_lista(Pilha **topo)//inicializa a lista
{
*topo = NULL;
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

void push(Pilha **N, char dado) {
  Pilha *novo;
  novo = Cria_Pilha();
  novo->dado = dado;
  novo->prox = *N;
  *N = novo;
}

int pop(Pilha **N, char *dado) {
  Pilha *aux;
  if(*N == NULL) //verifica se a lista está vazia
    return 0;
    else {
      *dado = (*N)->dado;
      aux = (*N)->prox;
      free(*N);
      *N = aux;
    }
  return 1;
}


int busca_lista(Pilha **N, char *dado){
  Pilha *aux;
  if (*N == NULL) {
    return 0;
    printf("Lista vazia !!!\n");
  } else {
    aux = *N;
      while(aux != NULL){
        if (aux->dado == *dado)
          return 1;
        else
          aux = aux->prox;
     }
     return 0;
  }
}


char imprime_lista_ecandeada(Pilha *N) {
  Pilha *aux;
  if(N == NULL)
    printf("\n A lista está vazia!!");
  else {
    for(aux = N; aux != NULL; aux = aux->prox)
      printf("\n%d", aux->dado);
    }
}

char Infixa_Posfixa(char dado[], Pilha *p);
void menuop();
int main ()
{
     Pilha *Lista;
     int menu,n=0;
     char op[40];
     inicializa_lista(&Lista);
     int i=0;
     char caractere;
        printf("entre com expressão");
        do{
            setbuf(stdin,NULL);
            caractere = getchar();
            op[i]= caractere;
            i++;
        }while(caractere != '\n');

     do
     {
         menuop();// apenas mostrar as opções
         setbuf(stdin,NULL);
         scanf("%d", &menu);


        switch(menu)
        {
              case 1:

             Infixa_Posfixa(op,&Lista);
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

 char Infixa_Posfixa(char dado[], Pilha *p){
        char item ;
        
        int i=0;
       do{
        item = dado[i];
        i++;
        if(item == '(')
            push(p,'(');
        if(item == ')')
            do{
                pop(p,item);
            }while(item =='(');

        }while(item != '\0');
     }

