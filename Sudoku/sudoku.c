//Nome: Vinícius Ferreira Schiavon RA: ************
//Programa feito para ler um sudoku de um arquivo e verificar se ele está correto ou não.
//OBS: o programa apresenta uma função "Escreve" que exibe o sudoku para o usuário, como o enunciado não exigia a escrita do 
// sudoku eu deixei essa função marcada como comentário, mas caso queira ver ela funcionando, basta remover as marcações de
// comentário do protótipo da função, da chamada da função na main e da função em si.

#include <stdio.h>
#include <stdlib.h>

int **CriaMatriz();
void LeituraSudoku(int **mat);
void VerificaSudoku(int **mat);
void LiberaMatriz(int **mat);
//void Escreve(int **mat);

int main()
{
    int **M;

    M = CriaMatriz();
    LeituraSudoku(M);
    //Escreve(M);
    VerificaSudoku(M);
    LiberaMatriz(M);

    return 0;
}

int **CriaMatriz()
{
 	int i;
	int **mat;

    mat = malloc (9 * sizeof (int *)); 
 	for (i = 0; i < 9; i++)
    {
 		mat[i] = malloc (9 * sizeof (int));
    }

	return (mat);
}

void LeituraSudoku(int **mat)
{
	int i, j;
	FILE *arq;
    arq = fopen("sudoku.txt", "r");
    if(arq == NULL) //Verificação da abertura do arquivo
    {
        printf("Erro na abertura do arquivo.");
        exit(EXIT_SUCCESS);
    }

    for(i = 0; i < 9; i++) //Percorimento da matriz e leitura dos valores
    {
        for(j = 0; j < 9; j++)
        {
            fscanf(arq, "%d", &mat[i][j]);
            if((mat[i][j] <= 0) || (mat[i][j] > 9)) //Verificação dos valores lidos
            {
                printf("Valores maiores que 9 ou menores (ou iguais) a 0 nao sao aceitos.");
                exit(EXIT_SUCCESS);
            }
        }
    }
    fclose (arq);
}

void VerificaSudoku(int **mat)
{
    int i, j, si, sj, aux, aux2, conti = 0, contj = 0;
    for(i = 0; i < 9; i++) //for de i e j são usados para definir o valor fixo que será comparado em cada linha e coluna
    {
        for(j = 0; j < 9; j++)
        {
            for(aux = 0; aux < 9; aux++) //for de aux é usado para alterar os valores que estão sendo comparados com o valor fixo
            {
                if(mat[aux][j] == mat[i][j]) //Verificação de repetição de número na coluna
                {
                    contj++;
                }
                if(mat[i][aux]== mat[i][j]) //Verificação de repetição de número na linha
                {
                    conti++;
                }
            }
            if((conti > 1) || (contj > 1))
            {
                break;
            }
            else
            {
                conti = 0;
                contj = 0;
            }
        }
        if((conti > 1) || (contj > 1))
        {
            break;
        }
    }
    if((conti > 1) || (contj > 1))
    {
        printf("\nSolucao invalida!");
        printf("\nEssa solucao possui elementos repetidos na mesma linha ou coluna.");
    }
    else
    {
        conti = 0;
        for(si = 0; si < 9; si = si + 3) //for de si e sj são usados para definir os parâmetros iniciais de cada matriz 3x3
        {
            for(sj = 0; sj < 9; sj = sj + 3)
            {
                for(i = 0; i < 3; i++) //for de i e j são usados para trocar o valor fixo que está sendo comparado com os demais da matriz 3x3
                {
                    for(j = 0; j < 3; j++)
                    {
                        for(aux = 0; aux < 3; aux++) //for de aux e aux2 são usados para alterar os valores que são comparados com o valor fixo
                        {
                            for(aux2 = 0; aux2 < 3; aux2++)
                            {
                                if(mat[si + aux][sj + aux2] == mat[si + i][sj + j]) //Verificação de repetição de número na matriz 3x3
                                {
                                    conti++;
                                }
                            }
                        }
                        if(conti > 1)
                        {
                            break;
                        }
                        else
                        {
                            conti = 0;
                        }
                    }
                    if(conti > 1)
                    {
                        break;
                    }
                }
                if(conti > 1)
                {
                    break;
                }
            }
            if(conti > 1)
            {
                break;
            }
        }
        if(conti > 1)
        {
            printf("\nSolucao invalida!");
            printf("\nEssa solucao contem elementos repetidos em uma matriz 3x3.");
        }
        else
        {
            printf("\nSolucao valida!");
        }
    }
}

/*void Escreve(int **mat)
{	
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            printf("%d ", mat[i][j]);
            if((j == 2) || (j == 5)){
                printf("| ");
            }
        }
        printf("\n");
        if((i == 2) || (i == 5)){
            printf("------|-------|-------");
            printf("\n");
        }
    }
}*/

void LiberaMatriz(int **mat)
{
    int i;
    for(i = 0; i < 9; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
