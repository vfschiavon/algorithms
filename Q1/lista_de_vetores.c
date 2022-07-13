//Nome: Vinícius Ferreira Schiavon RA: ************
/*Programa feito para realizar as operações de inserção, remoção, compactação e impressão em uma lista de vetores*/

#include<stdio.h>
#include<stdlib.h>

struct celula
{
    int v[3];
    int cont;
    struct celula *prox;
};
typedef struct celula cel;

int Menu();
void InsereValor(cel **ini, int valor);
void RemoveValor(cel **ini, int valor);
void CompactaLista(cel **ini);
void ImprimeLista(cel **ini);
void AtualizaVetor(cel *aux, int pos);

int main()
{
    cel *inicio;
    int valor, op = 0;
    inicio = NULL;

    while (op != 5) //Verificador de término das operações
    {
        op = Menu();
        switch (op) //Escolha de qual operação será realizada
        {
            case 1: //Inserir valor
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                InsereValor(&inicio, valor);
            break;
            case 2: //Remover valor
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                RemoveValor(&inicio, valor);
            break;
            case 3: //Compactar lista
                CompactaLista(&inicio);
            break;
            case 4: //Imprimir a lista para o usuário
                ImprimeLista(&inicio);
            break;
            case 5: //Finalizar
            break;
            default:
                printf("Escolha invalida.\n");
            break;
        }
    }
    printf("\nFim das operacoes.");

    return 0;
}

int Menu()
{
    int n;
    //Lista das operações exibida ao usuário
    printf("\n===================");
    printf("\n1 - Insere valor.\n");
    printf("2 - Remove valor.\n");
    printf("3 - Compacta lista.\n");
    printf("4 - Imprime lista.\n");
    printf("5 - Finalizar.\n");
    printf("=> "); //Escolha da operação
    scanf("%d", &n);

    return(n);
}

void InsereValor(cel **ini, int valor)
{
    cel *aux;
    aux = *ini;

    //Verifica se o vetor de três posições chegou ao fim e adiciona o novo valor na posição correta
    while (aux != NULL)
    {
        if (aux->cont < 3)
        {
            aux->v[aux->cont] = valor;
            aux->cont++;
            return;
        }
        else
        {
            aux = aux->prox;
        }
    }

    aux = malloc(sizeof (cel));
    aux->v[0] = valor;
    aux->cont = 0;
    aux->cont++;

    if (*ini == NULL)
    {
        aux->prox = NULL;
    }
    else
    {
        aux->prox = *ini;
    }
    *ini = aux;
}

void RemoveValor(cel **ini, int valor)
{
    cel *aux, *aux2;
    int i;
    aux = *ini;
    
    while (aux != NULL)
    {
        for (i = 0; i < aux->cont; i++) //Percorrimento dos vetores
        {
            if (aux->v[i] == valor) //Encontrar o valor desejado e removê-lo
            {
                aux->v[i] = 0;
                aux->cont--;
                printf("Valor removido.\n");
                if (aux->cont == 0)
                {
                    if (aux == *ini)
                    {
                        *ini = aux->prox;
                    }
                    else
                    {
                        aux2->prox = aux->prox;
                    }
                    free(aux);

                    return;
                }
                AtualizaVetor(aux, i);

                return;
            }
        }
        aux2 = aux;
        aux = aux->prox;
    }
    printf("Valor nao removido.\n");
}

void CompactaLista(cel **ini)
{
    cel *aux, *aux2;
    aux = *ini;

    if (aux == NULL)
    {
        return;
    }

    while (aux->prox != NULL)
    {
        while ((aux->cont != 3) && (aux->prox != NULL)) //Compacta a lista de vetores, removendo os espaços vazios 
        {
            aux2 = aux->prox;
            aux->v[aux->cont] = aux2->v[0];
            AtualizaVetor(aux2, 0);
            aux2->cont--;
            aux->cont++;
            
            if (aux2->cont == 0) //Liberação da célula não mais utilizada
            {
                aux->prox = aux2->prox;
                free(aux2);
            }
        }
        aux = aux->prox;
        if (aux == NULL)
        {
            break;
        }
    }
}

void ImprimeLista(cel **ini)
{
    cel *aux;
    int i, j = 0;
    aux = *ini;

    while (aux != NULL) //Imprime a lista de valores identificando qual valor está em qual vetor
    {
        printf("\nVetor %d: ", j);
        for (i = 0; i < aux->cont; i++)
        {
            printf("%d ", aux->v[i]);
        }
        j++;
        aux = aux->prox;
    }
    printf("\n");
}

void AtualizaVetor(cel *aux, int pos)
{
    int i;

    for (i = pos; i < aux->cont; i++) //Atualiza a posição dos valores no vetor
    {
        aux->v[i] = aux->v[i+1];
    }
}
