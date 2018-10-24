#include<stdio.h>
#include<stdlib.h>
// Definição da Estrutura Lista Linear Simplemente Encadeada
typedef struct Bloco
{
char dado;
struct Bloco *prox;
}  Pilha;

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

void imprime_lista_ecandeada(Pilha *N) {
  printf("entrei na função imprime_lista_ecandeada\n" );
  Pilha *aux;
  if(N == NULL)
    printf("\n A lista está vazia!!");
  else {
    for(aux = N; aux != NULL; aux = aux->prox)
      printf("\n fila : %c ", aux->dado);
    }
}

char Infixa_Prefixa(char dado[], Pilha **p);
char Infixa_Posfixa(char dado[], Pilha **p);
void menuop();
int Prioridade(char c, char t);
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
              Infixa_Posfixa(op,&Lista);

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

 char Infixa_Posfixa(char dado[], Pilha **p){
      char item ;
      int t;
      char ret;
      int controle=1;
      int i=0;
      push(p,'(');
       do
       {
        item = dado[i];
        i++;
       if(item >= 'a' && item <= 'z')
       {
            printf("%c", item);
        }
      else if(item == '(')
            push(p,'(');
      else if(item == ')' || '\0')
      {
        do{
          t = pop(p,&ret);
            if(t == 0)
              printf("Lista vazia\n" );
              else if(ret != '(');
              printf("%c\n", ret);
          }while(item !='(');

      }else if(item == '+' || item == '-' ||  item == '*' || item == '/' ||  item == '^' )
      {
      while(controle)
      {
          t = pop(p,&ret);

          if(t == 0 )
          {
            printf("Lista vazia");
            controle =0;
          }else
          {
          if(Prioridade(item,ret))
            {

              push(p,ret);
              push(p,item);
              printf("%c\n",ret );
              printf("%c\n",item);
              break;
            }
        if(Prioridade(item,ret)){
              printf("%s\n",ret);

            }

          }
        }
      }


    }while(item != '\0');
}

char Infixa_Prefixa(char dado[], Pilha **p){
     char item ;
     int t;
     char ret;
     int i=0;
     push(p,'(');
      do
      {
       item = dado[i];
       i++;
       if(item == '+' || item == '-' ||  item == '*' || item == '/' ||  item == '^' )
       {
       while(1)
       {
           t = pop(p,&ret);

           if(t == 0 )
           {
             printf("Lista vazia");
             break;
           }else
           {
             if(Prioridade(item,ret))
             {
               push(p,ret);
               push(p,item);
               break;
             }

             printf("%c", ret);

           }

       }
     }
    else if(item >= 'a' && item <= 'z')
      {
           printf("%c", item);
       }
     else if(item == '(')
           push(p,'(');
     else if(item == ')' || '\0')
     {
       do{
         t = pop(p,&ret);
           if(t == 0)
             printf("Lista vazia\n" );
             else if(ret != '(');
             printf("%c\n", ret);
         }while(item !='(');

     }

   }while(item != '\0');
}
int Prioridade(char c, char t){
  int pc,pt;

  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;

  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;

  return (pc > pt);
}
