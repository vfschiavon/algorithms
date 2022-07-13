//Nome: Vinícius Ferreira Schiavon RA: ************
/*Programa feito para ler um sudoku X de um arquivo e verificar se ele está correto ou não.
OBS: o programa apresenta uma função "Escreve" que exibe o sudoku para o usuário, como o enunciado não exigia a escrita do 
sudoku eu deixei essa função marcada como comentário, mas caso queira ver ela funcionando, basta remover as marcações de
comentário do protótipo da função, da chamada da função na main e da função em si.*/

#include <stdio.h>
#include <stdlib.h>

int **CriaMatriz();
void LeituraSudokuX(int **mat);
void VerificaSudokuX(int **mat);
void LiberaMatriz(int **mat);
//void Escreve(int **mat);

int main()
{
    int **sudoku;

    sudoku = CriaMatriz();
    LeituraSudokuX(sudoku);
    //Escreve(sudoku);
    VerificaSudokuX(sudoku);
    LiberaMatriz(sudoku);

    return (0);
}

int **CriaMatriz()
{
 	int i;
	int **mat;

    mat = malloc (12 * sizeof (int *)); 
 	for (i = 0; i < 12; i++)
    {
 		mat[i] = malloc (12 * sizeof (int));
    }

	return (mat);
}

void LeituraSudokuX(int **mat)
{
	int i, j;
	FILE *arq;
    arq = fopen("sudoku_x.txt", "r");
    if (arq == NULL) //Verificação da abertura do arquivo
    {
        printf("Erro na abertura do arquivo.");
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < 12; i++) //Percorrimento da matriz e leitura dos valores
    {
        for (j = 0; j < 12; j++)
        {
            fscanf(arq, "%d", &mat[i][j]);
            if ((mat[i][j] <= 0) || (mat[i][j] > 12)) //Verificação dos valores lidos
            {
                printf("Valores maiores que 9 ou menores (ou iguais) a 0 nao sao aceitos.");
                exit(EXIT_SUCCESS);
            }
        }
    }
    fclose (arq);
}

void VerificaSudokuX(int **mat)
{
    int i, j, si, sj, aux, aux2, conti = 0, contj = 0;

    for (i = 0; i < 12; i++) //for de i e j são usados para definir o valor fixo que será comparado em cada linha e coluna
    {
        for (j = 0; j < 12; j++)
        {
            for (aux = 0; aux < 12; aux++) //for de aux é usado para alterar os valores que estão sendo comparados com o valor fixo
            {
                if (mat[aux][j] == mat[i][j]) //Verificação de repetição de número na coluna
                {
                    contj++;
                }
                if (mat[i][aux]== mat[i][j]) //Verificação de repetição de número na linha
                {
                    conti++;
                }
            }
            if ((conti > 1) || (contj > 1))
            {
                break;
            }
            else
            {
                conti = 0;
                contj = 0;
            }
        }
        if ((conti > 1) || (contj > 1))
        {
            break;
        }
    }

    if ((conti > 1) || (contj > 1))
    {
        printf("\nSolucao invalida!\nEssa solucao possui elementos repetidos na mesma linha ou coluna.");
    }
    else
    {
        conti = 0;
        for (si = 0; si < 12; si = si + 3) //for de si e sj são usados para definir os parâmetros iniciais de cada matriz 3x4
        {
            for (sj = 0; sj < 12; sj = sj + 4)
            {
                for (i = 0; i < 3; i++) //for de i e j são usados para trocar o valor fixo que está sendo comparado com os demais da matriz 3x4
                {
                    for (j = 0; j < 4; j++)
                    {
                        for (aux = 0; aux < 3; aux++) //for de aux e aux2 são usados para alterar os valores que são comparados com o valor fixo
                        {
                            for (aux2 = 0; aux2 < 4; aux2++)
                            {
                                if (mat[si + aux][sj + aux2] == mat[si + i][sj + j]) //Verificação de repetição de número na matriz 3x4
                                {
                                    conti++;
                                }
                            }
                        }
                        if (conti > 1)
                        {
                            break;
                        }
                        else
                        {
                            conti = 0;
                        }
                    }
                    if (conti > 1)
                    {
                        break;
                    }
                }
                if (conti > 1)
                {
                    break;
                }
            }
            if (conti > 1)
            {
                break;
            }
        }

        if (conti > 1)
        {
            printf("\nSolucao invalida!\nEssa solucao contem elementos repetidos em uma matriz 3x4.");
        }
        else
        {
            conti = 0;
            contj = 0;
            sj = 11;
            j = 11;
            for (si = 0; si < 12; si++) //for de si e a variável sj são usados para definir o valor fixo que está sendo comparado com os demais de cada diagonal
            {
                for (i = 0; i < 12; i++) //for de i e a variável j são usados para alterar os valores que são comparados com o valor fixo
                {
                    if (mat[i][i] == mat[si][si]) //Comparador da diagonal principal
                    {
                        conti++;
                    }

                    if (mat[i][j] == mat[si][sj]) //Comparador da diagonal secundária
                    {
                        contj++;
                    }
                    j--;
                }

                if (conti > 1) //Verificador da diagonal principal
                {
                    break;
                }
                else
                {
                    conti = 0;
                }

                if (contj > 1) //Verificador da diagonal secundária
                {
                    break;
                }
                else
                {
                    contj = 0;
                    j = 11;
                    sj--;
                }
            }

            if (conti > 1)
            {
                printf("\nSolucao invalida!\nEssa solucao possui elementos repetidos na diagonal principal.");
            }
            else if (contj > 1)
            {
                printf("\nSolucao invalida!\nEssa solucao possui elementos repetidos na diagonal secundaria.");
            }
            else
            {
                printf("\nSolucao valida!");
            }
        }
    }
}

// void Escreve(int **mat)
// {	
//     int i, j;

//     for (i = 0; i < 12; i++)
//     {
//         for (j = 0; j < 12; j++)
//         {
//             if (mat[i][j] < 10)
//             {
//                 printf(" %d ", mat[i][j]);
//             }
//             else
//             {
//                 printf("%d ", mat[i][j]);
//             }

//             if ((j == 3) || (j == 7))
//             {
//                 printf("| ");
//             }
//         }
//         printf("\n");

//         if ((i == 2) || (i == 5) || (i == 8))
//         {
//             printf("------------|-------------|-------------\n");
//         }
//     }
// }

void LiberaMatriz(int **mat)
{
    int i;

    for (i = 0; i < 12; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
