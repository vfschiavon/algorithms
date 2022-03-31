#include <stdio.h>
#include <stdlib.h>
int main(){

    //Declaração das variáveis utilizadas
    int  si, sj, i, j, aux1, aux2, conti = 0, contj = 0, m[9][9];

    //Leitura do arquivo sudoku
    FILE *arq;
    arq = fopen("sudoku.txt", "r");
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            fscanf(arq, "%d", &m[i][j]);
            if((m[i][j] <= 0) || (m[i][j] > 9)){
                printf("Valores maiores que 9 ou menores (ou iguais) a 0 nao sao aceitos.");
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose (arq);

    //Escrita do sudoku formatada
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            printf("%d ", m[i][j]);
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

    //Verificação de validade do sudoku
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            for(aux1=0; aux1<9; aux1++){
                if(m[aux1][j] == m[i][j]){
                    conti++;
                }
                if(m[i][aux1] == m[i][j]){
                    contj++;
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
        if((conti > 1) || (contj > 1)){
            break;
        }
    }
    if((conti > 1) || (contj > 1)){
        printf("\nSolucao invalida.");
    }
    else
    {
        conti = 0;
        for(si = 0; si < 9; si = si + 3)
        {
            for(sj = 0; sj < 9; sj = sj + 3)
            {
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 3; j++)
                    {
                        for(aux1 = 0; aux1 < 3; aux1++)
                        {
                            for(aux2 = 0; aux2 < 3; aux2++)
                            {
                                if(m[si + aux1][sj + aux2] == m[si + i][sj + j])
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
            printf("\nSolucao invalida.");
        }
        else
        {
            printf("\nSolucao valida.");
        }
    }
    
    return 0;
}