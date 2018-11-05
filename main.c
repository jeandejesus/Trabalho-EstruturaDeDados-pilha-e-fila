#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

// Definição da Estrutura Lista Linear Simplemente Encadeada
typedef struct Bloco
{
char dado;
struct Bloco *prox;
} Pilha;

typedef struct BlocoNumero
{
float num;
struct BlocoNumero *prox;
} PilhaNumero;


void inicializa_lista(Pilha **topo)//inicializa a lista
{
    *topo = NULL;
}
void inicializa_lista_numero(PilhaNumero **topo)//inicializa a lista
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
Pilha * Cria_Pilha_numero() //aloca memória para o Pilha
{
  PilhaNumero *p;
  p = (PilhaNumero *) malloc(sizeof(PilhaNumero));
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
      return 1;
    }
}

void pushN(PilhaNumero **N, float num) {
   // printf(" %f",dado);
  PilhaNumero *novoN;
  novoN = Cria_Pilha_numero();
  novoN->num = num;
  novoN->prox = *N;
  *N = novoN;

}

int popN(PilhaNumero **N, float *num) {
  PilhaNumero *auxN;
  if(*N == NULL) //verifica se a lista está vazia
    return 0;
    else {
      *num = (*N)->num;
      auxN = (*N)->prox;
      free(*N);
      *N = auxN;
      return 1;
    }
}

void imprime_lista_ecandeada(Pilha *N) {
  Pilha *aux;
  if(N == NULL)
    printf("\n A lista está vazia!!");
  else {
    for(aux = N; aux != NULL; aux = aux->prox)
    {
      printf("\n fila : %c ", aux->dado);
    }
    }
}
void imprime_lista_numero(PilhaNumero *N) {
  PilhaNumero *aux;
  if(N == NULL)
    printf("\n A lista está vazia!!");
  else {
    for(aux = N; aux != NULL; aux = aux->prox)
    {
      printf(" : %f ", aux->num);
    }
    }
}

int validaExpressao(char op[], Pilha *p){
   int valida = 1;
    int i = 0;
    char c;

    while( (op[i] != '\0') && (valida != 0) ){

        if((op[i] == '(') || (op[i] == '[') || (op[i] == '{'))
            push(&p,op[i]);

        if((op[i] == ')') || (op[i] == ']') || (op[i] == '}')){
            if( p->prox==NULL )
                valida = 0;
            else{
                 (char) pop(p,&c);

                switch(op[i]){
                    case ')':
                        if( c != '(' )
                            valida = 0;
                        break;
                    case ']':
                        if( c != '[' )
                            valida = 0;
                        break;
                    case '}':
                        if( c != '{' )
                            valida = 0;
                        break;
                }
            }
        }
        i++;
    }

    if(p->prox==NULL && valida == 1)
        return 1;
    else
        return 0;
}


int isMatchingPair(char character1, char character2);
int validarEXpressao(char exp[],Pilha **stack);
void calcular(char dado[]);
char Infixa_Prefixa(char dado[], Pilha **p);
char Infixa_Posfixa(char dado[], Pilha **p,char posf[]);
void menuop();
int Prioridade(char c, char t);
int main ()
{
      Pilha *Lista;
     int menu,n=0;
     char op[40],posf[40],result[14];
     inicializa_lista(&Lista);
     int i=0,valida=0;
     float item[40];
        printf("entre com expressão");
        setbuf(stdin,NULL);
        scanf("%s",op);
        fflush(stdin);
        printf("%s",op);
     do
     {
         menuop();// apenas mostrar as opções
         setbuf(stdin,NULL);
         scanf("%d", &menu);
         fflush(stdin);


        switch(menu)
        {
              case 1:

               Infixa_Posfixa(op,&Lista,posf);
                printf("resultado : %s",posf);
              break;
              case 2 :
                Infixa_Prefixa(op,&Lista);
              break;
              case 3 :
               valida = validarExpressao(op,&Lista);
               if(valida == 1 && strlen(op) > 2)
                    printf("Essa expressão é valida %d\n",valida);
                else
                    printf("Essa expressão é invalida %d\n",valida);
                break;
              case 4:
                valida = validarExpressao(op);
                if(valida == 1){
                Infixa_Posfixa(op,&Lista,posf);
                calcular(posf);
                }else
                printf("Essa expressão é invalida %d\n",valida);
              break;
              case 5 :
                return(0);
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


char   Infixa_Posfixa(char dado[], Pilha **p,char posf[]){
       char item ;
      int t;
      char ret,result[40];
      int aux=1;
      int i=0,j=1;
      push(p,'(');
      fflush(stdin);
       do
       {
        item = dado[i];
        i++;
       if(item >= 47 && item <= 58)
       {
            posf[j++]=item;

        }
       else if(item == '(')
          {
           posf[j++] = item;
            push(p,'(');
          }
      else if(item == ')' || item == '\0')
      {
        do{
          t = pop(p,&ret);
          if(ret != '(')
            {
              posf[j++] = ret;
              posf[j++]=' ';

            }
          }while(ret !='(');

      }else if(item == '+' || item == '-' ||  item == '*' || item == '/' ||  item == '^' )
      {
        posf[j++]=' ';
        int fim = 0;
        do {

          t = pop(p,&ret);
          if(Prioridade(item,ret))
            {

              push(p,ret);
              push(p,item);

             fim = 1;

            }else {


              posf[j++] = ret;

            }


          }while (!fim);
      }


    }while(item != '\0');
    posf[j++]='\0';

}


 reverte(char dado[], Pilha **p, char auxiliar[]){

  int size=strlen(dado)-1;    //strlen calcula a quantidade de caracteres que tem a string
  int a=0;

    for(a=0;dado[a]!='\0';a++){        //Repete enquanto nao chegar ao final da string
         auxiliar[size]=dado[a];

         size--;
    }
    auxiliar[a++]='\0';//Se nao colocar essa parte, o programa pode mostrar LIXO
}


char  Infixa_Prefixa(char dado[], Pilha **p){

      char reversa[40],pre[40],rev[40],resultado[40],str[40];
      int j=0,i=0;
      sscanf(&dado[i], "%s", &rev[i]);

      reverte(rev,p,reversa);

      for (int i = 0; i < strlen(reversa)-1; i++) {

        if (reversa[i] == '(') {
            reversa[i] = ')';
            i++;
        }
        else if (reversa[i] == ')') {
                reversa[i] = '(';
                i++;
        }

      }
      Infixa_Posfixa(reversa,p,pre);
      int x=1;
      do{
        str[j++]=pre[x];
        x++;
      }while(pre[x]!='\0');
      str[j++]='\0';
    reverte(str,p,resultado);
    printf("RESULTADO");
    printf(" [%s]\n",resultado);

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


void calcular(char dado[])
{
    PilhaNumero *pn;
    inicializa_lista_numero(&pn);
    int i=1,j=0,x=0;
    float a=0,b=0,item=0,numero=0 ;
    char conv,caractere[50],maior[50];


    do{
        if(dado[i] == '+'){
                popN(&pn,&a);
                popN(&pn,&b);
                printf("\n soma %f + %f  = %f \n",a,b,(a+b));
                pushN(&pn,a+b);

        }else if( dado[i] == '-'){
                popN(&pn,&a);
                popN(&pn,&b);
                printf("\n subitração %f - %f  = %f \n",b,a,(b-a));
                pushN(&pn,b-a);
        }
        else if( dado[i] == '*'){
                popN(&pn,&a);
                popN(&pn,&b);
                printf("\n multiplicação %f * %f  = %f \n",a,b,(a*b));
                pushN(&pn,a*b);
        } else if( dado[i] == '/'){
                popN(&pn,&a);
                popN(&pn,&b);
                printf("\n divisao %f / %f  = %f \n",a,b,(a/b));
                pushN(&pn,a/b);

        }else if( dado[i] == '^'){
                popN(&pn,&a);
                popN(&pn,&b);
                printf("\n exponenciação %f ^ %f  = %f \n",a,b,(pow(a,b)));
                pushN(&pn,pow(a,b));
        }
        else if(dado[i] >= '0' && dado[i] <= '9' ) {
            sscanf(&dado[i], "%f", & numero);
            while(dado[i] >= '0' && dado[i] <= '9')
                i++;
            i--;
            pushN(&pn,numero);
        }

        i++;

    }while(dado[i]!= '\0');

       printf("\n o resultado da expressão é :");
       imprime_lista_numero(pn);


}


int isMatchingPair(char character1, char character2)
{
   if(character1 == '(' && character2 == ')')
     return 1;
   else if(character1 == '{' && character2 == '}')
     return 1;
   else if(character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

 int validarExpressao(char exp[],Pilha **stack)
{  int i = 0;
   //struct Pilha *stack = NULL;

   while(exp[i])
   {

      if(exp[strlen(exp)-1] == '+' || exp[strlen(exp)-1]=='-' || exp[strlen(exp)-1]=='*' || exp[strlen(exp)-1]=='/' || exp[strlen(exp)-1]=='^')
        return 0;

      if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        push(&stack, exp[i]);


      if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[' || exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){

        if (exp[i+1] == '}' || exp[i+1] == ')' || exp[i+1] == ']' || exp[i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='*' || exp[i+1]=='/' || exp[i+1]=='^')
         return 0;
      }

      if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
      {
         if(stack == NULL)
           return 0;

         else if ( !isMatchingPair(pop(&stack,exp[i]), exp[i]) )
           return 0;
      }
      i++;
   }


   if(stack == NULL)
     return 1; /*balanced*/
   else
     return 0;  /*not balanced*/
}


