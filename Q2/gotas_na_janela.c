//Nome: Vinícius Ferreira Schiavon RA: ************
/*Programa feito para simular gotas de chuva escorrendo de uma janela e dizer quantos passos foram até ela ficar totalmente seca.
OBS: o tempo da função sleep, no Windows, é definido em segundos, ou seja, se sleep(3) então o programa espera 3 segundos até voltar, não sei
se no Linux é em segundos também ou se é em milissegundos.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LIN 15
#define MAX_COL 15

void Escreve(char m[MAX_LIN][MAX_COL]);
int Verifica(char m[MAX_LIN][MAX_COL]);

int main()
{
    int i, j, aux1, aux2, dif = 1, count = 0;
    char gota, M[MAX_LIN][MAX_COL];

    for (i = 0; i < MAX_LIN; i++) //Insere as bordas e o "vidro" da janela
    {
        for (j = 0; j < MAX_COL; j++)
        {
            if (i == 0) //Borda superior
            {
                M[i][j] = 45;
            }
            else if (i == (MAX_LIN - 1)) //Borda inferior
            {
                M[i][j] = 43;
            }
            else if ((j == 0) || (j == (MAX_COL - 1))) //Bordas laterais
            {
                M[i][j] = 124;
            }
            else //"Vidro"
            {
                M[i][j] = 48;
            }
        }
    }

    FILE *arq; //Leitura das coordenadas das gotas
    arq = fopen("gotas_na_janela.txt", "r");
    if (arq == NULL) //Verificação da abertura do arquivo
    {
        printf("Erro na abertura do arquivo.");
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < (MAX_LIN * MAX_COL); i++)
    //Esse for possui um valor limite alto propositalmente, pois existe um break mais abaixo no código, essa combinação garante a leitura de todos as possíveis coordenadas das gotas
    {
        for (j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                fscanf(arq, "%d", &aux1); //Leitura da linha em que a gota estará 
            }
            else if (j == 1)
            {
                fscanf(arq, "%d", &aux2); //Leitura da coluna em que a gota estará
            }
            else
            {
                fscanf(arq, "%c", &gota); //Leitura do tipo de gota
            }
        }

        if ((aux1 == 0) && (aux2 == 0)) //Verificação de término da leitura
        {
            break;
        }
        else if ((aux1 < MAX_LIN - 1) && (aux2 < MAX_COL - 1) && (aux1 > 0) && (aux2 > 0))
        //Verificando se as coordenadas não extrapolam os valores limites das bordas
        {
            M[aux1][aux2] = gota;
        }
    }
    fclose (arq);

    printf("A chuva parou!\n");
    Escreve(M);

    while (dif != 0)
    {
        for (i = (MAX_LIN - 2); i >= 0; i--) //Atualização das gotas da janela
        {
            for (j = (MAX_COL - 2); j >=0; j--)
            {
                if ((M[i][j] == 78) || (M[i][j] == 110))
                {
                    M[i][j] = 48;
                    if (i + 1 < (MAX_LIN - 1))
                    {
                        M[i+1][j] = 78;
                    }
                }
                else if ((M[i][j] == 69) || (M[i][j] == 101))
                {
                    M[i][j] = 48;
                    if (i + 2 < (MAX_LIN - 1))
                    {
                        M[i+2][j] = 69;
                    }

                    if ((M[i+1][j] == 78) || (M[i][j] == 110)) //Sumir com a gota lenta caso a rápida passe por ela
                    {
                        M[i+1][j] = 48;
                    }
                }
            }
        }
        count++;

        sleep (1); //Caso deseje uma pausa maior entre cada atualização basta trocar o valor da função sleep

        Escreve(M); //Printa a janela para o usuário

        dif = Verifica(M); //Verifica se a janela já está seca ou se deve ser atualizada mais vezes
    }

    printf("\nA janela secou!\nForam necessarios %d passos para secar totalmente a janela.", count);

    return 0;
}

void Escreve(char m[MAX_LIN][MAX_COL])
{
    int i, j;

    printf("\n");
    for (i = 0; i < MAX_LIN; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            if (m[i][j] == 48)
            {
                printf("  ");
            }
            else if (m[i][j] == 110)
            {
                printf("N ");
            }
            else if (m[i][j] == 101)
            {
                printf("E ");
            }
            else
            {
                printf("%c ", m[i][j]);
            }
        }
        printf("\n");
    }
}

int Verifica(char m[MAX_LIN][MAX_COL])
{
    int i, j, dif = 0;

    for (i = 0; i < MAX_LIN; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            if ((m[i][j] == 78) || (m[i][j] == 69))
            {
                dif = 1;
                break;
            }
            else
            {
                dif = 0;
            }
        }
        if (dif == 1)
        {
            break;
        }
    }

    return (dif);
}
