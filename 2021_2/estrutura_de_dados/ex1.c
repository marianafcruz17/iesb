#include <stdio.h>
#include <stdlib.h>

typedef struct lista_ligada
{
    int qtd;
    struct registro * inicio;
}lista_ligada;

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;

lista_ligada * aloca_lista();
registro * aloca_registro();
void incluir_no_fim_da_lista(lista_ligada * l, int x);
void mostrar_lista(lista_ligada * l);
int remover_registro_da_lista(int valor_para_apagar, lista_ligada * l );

int main()
{

    lista_ligada * l1, * l2;
    
    l1=aloca_lista();
    l2=aloca_lista();

    incluir_no_fim_da_lista(l1,1);
    incluir_no_fim_da_lista(l1,2);
    incluir_no_fim_da_lista(l1,3);
    incluir_no_fim_da_lista(l1,4);
    incluir_no_fim_da_lista(l1,5);

    printf("\n Mostrando conteudo de L1: ");
    mostrar_lista(l1);

    incluir_no_fim_da_lista(l2,10);
    incluir_no_fim_da_lista(l2,20);
    incluir_no_fim_da_lista(l2,30);
    incluir_no_fim_da_lista(l2,40);
    incluir_no_fim_da_lista(l2,50);
    printf("\n Mostrando conteudo de L2: ");
    mostrar_lista(l2);

    printf("\n");
    return 0;
}

lista_ligada * aloca_lista()
{
    lista_ligada * novo;
    novo = (lista_ligada*)calloc(1,sizeof(lista_ligada));
    novo->inicio=NULL;

    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}

void incluir_no_fim_da_lista(lista_ligada * l, int x)
{
    registro * novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio = novo;   
    }
    else
    {
        aux = l->inicio;

        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista_ligada * l)
{
    if (l==NULL){
        printf("\n Lista nao alocada");
        return;
    }

    if (l->inicio==NULL)
    {
        printf("\n Lista sem elementos");
        return;
    }

    registro * aux;

    aux = l->inicio;

    while(aux!=NULL)
    {
        printf("\n -> %d",aux->valor);
        aux=aux->prox;   
    }
}


//0 - não conseguir apagar um elemento.
//1 - conseguir apagar um elemento.

int remover_registro_da_lista(int valor_para_apagar, lista_ligada * l )
{
    if (l==NULL)
    {
        printf("\nLista inexistente");
        return 0;
    }   

    if (l->inicio==NULL)
    {
        printf("\nLista vazia");
        return 0;
    }

    registro * aux=l->inicio,*ant=NULL;
    int encontrou=0;
    while(aux!=NULL && encontrou==0)
    {
        if (aux->valor == valor_para_apagar){
            ant->prox = aux->prox;
            free(aux);
            l->qtd--;
            encontrou=1;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    if (encontrou)
        return 1;
    else
        return 0;

}

