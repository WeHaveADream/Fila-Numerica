#include<stdlib.h>
#include<stdio.h>

typedef struct Tfila{
  int dado;
  struct Tfila *prox;
}Tfila;

typedef struct FILA_PACIENTES{
 Tfila *inicio;
 Tfila *fim;
}FILA_PACIENTES;

void createfila(FILA_PACIENTES *f){
  f->inicio =NULL;
  f->fim    =NULL;
}

int fila_vazia(FILA_PACIENTES *f){

  if(f->inicio==NULL){
    return 1; //fila vazia
  }else{
    return 0; //fila não está vazia
  }
}

void insere_fila(FILA_PACIENTES *f,int valor){

  Tfila *novo= malloc(sizeof(Tfila));
  novo->dado = valor;
  novo->prox = NULL;


  if(fila_vazia(f)==1){//primeira vez na fila
    f->inicio = novo;
    f->fim    = novo;


  }else{
    f->fim->prox = novo;
    f->fim = novo; //ajusta o ponteiro do fim

  }

    novo=NULL;
    free(novo);


}


int remove_fila(FILA_PACIENTES *f){
  int valor;

  Tfila *aux=malloc(sizeof(Tfila));

  aux=f->inicio; //aux aponta para o inicio da fila

  valor = aux->dado; //guardando o valor na variável

  f->inicio = aux->prox; //ajustando o ponteiro do inicio


  aux->prox = NULL;

  if(f->inicio==NULL){ //verifico se existe um só elemento
    f->fim=NULL;
    free(aux);
  }else{
   free(aux);
  }

  return valor;

}




void mostrar_fila(FILA_PACIENTES *f){

 Tfila *aux=malloc(sizeof(Tfila));

 aux = f->inicio;

     while(aux!= NULL){
        printf(" | %d",aux->dado);
        aux=aux->prox;

     }
   free(aux);

}
void menu(){

  FILA_PACIENTES *f= malloc(sizeof(FILA_PACIENTES));
  createfila(f);


 int op;  //opção recursiva

 do{
     system("cls");
     printf("\n Fila: \n");
     mostrar_fila(f);

     printf("\n\n");
     printf("1 - Enfileirar \n");
     printf("2 - Desenfileirar \n");
     printf("3 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

      case 1:{
         int x;
         printf("Informe o valor :");
         scanf("%d",&x);
         insere_fila(f,x);
        //insere_fila( 2a , 30)


         break;
     }


     case 2:{//remover fila
          int x;
          if(fila_vazia(f)==1){
            printf("\n nao e possivel remover ");
            printf(" ------>fila vazia!! \n");
            getch( );
          }else{
              x=remove_fila(f);
              printf("\n \t valore retirado %d ",x);
              getch( );
          }
          break;

      }

     case 3:
        op=3;
    }

 }while(op != 3);

}

int main()
{
    menu();

    printf("\n\n");
    return 0;
}
