//Nome: Vinícius Ferreira Schiavon RA: 202100560434 
#include <stdio.h>
//#include <math.h>
/*Li em alguns lugares que pra usar a função roundf é necessário o math.h, no meu computador rodou sem essa biblioteca sem problemas, mas
caso ocorra algum problema referente a função roundf é só remover as duas barras na frente do include.*/

int *calcuni(float n);

int main()
{

    float n;
    printf("Digite o valor: ");
    scanf("%f", &n);

    while(n != 0)
    {

        if((n < 0) || (n >= 10000))
        {

            printf("Valores negativos ou maiores (ou iguais) a R$10.000 nao sao aceitos.");

        }
        else
        {

            int *p, m, c, d, u, dec, cent;
            char *centenas[] = {"cento", "cem", "duzentos", "trezentos", "centos", "quinhentos"};
            char *dezenas[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze",  "dezes", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "nta",  "oitenta"};
            char *unidades[] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
            char *extra[] = {"e", "mil", "reais", "centavos", "real", "centavo"};

            p = calcuni(n);

            m = *p; //milhares
            c = *(p+1); //centenas
            d = *(p+2); //decimais
            u = *(p+3); //unidades
            dec = *(p+4); //décimos
            cent = *(p+5); //centésimos

            switch (m)
            {
                case 2:
                    printf("%s ", unidades[1]);
                break;
                case 3:
                    printf("%s ", unidades[2]);
                break;
                case 4:
                    printf("%s ", unidades[3]);
                break;
                case 5:
                    printf("%s ", unidades[4]);
                break;
                case 6:
                    printf("%s ", unidades[5]);
                break;
                case 7:
                    printf("%s ", unidades[6]);
                break;
                case 8:
                    printf("%s ", unidades[7]);
                break;
                case 9:
                    printf("%s ", unidades[8]);
                break;
            }

            if(m != 0)
            {
                printf("%s %s ", extra [1], extra[0]);
            }

            switch (c)
            {
                case 1:
                    if((d == 0) && (u == 0))
                    {
                        printf("%s ", centenas[1]);
                    }
                    else
                    {
                        printf("%s ", centenas[0]);
                    }
                break;
                case 2:
                    printf("%s ", centenas[2]);
                break;
                case 3:
                    printf("%s ", centenas[3]);
                break;
                case 4:
                    printf("%s%s ", unidades[3], centenas[4]);
                break;
                case 5:
                    printf("%s ", centenas[5]);
                break;
                case 6:
                    printf("%s%s ", unidades[5], centenas[4]);
                break;
                case 7:
                    printf("%s%s ", unidades[6], centenas[4]);
                break;
                case 8:
                    printf("%s%s ", unidades[7], centenas[4]);
                break;
                case 9:
                    printf("%s%s ", unidades[8], centenas[4]);
                break;
            }

            if((d != 0) && (u != 0) && (c != 0))
            {
                printf("%s ", extra [0]);
            }

            switch (d)
            {
                case 1:
                    switch (u)
                    {
                        case 0:
                            printf("%s ", dezenas[0]);
                        break;
                        case 1:
                            printf("%s ", dezenas[1]);
                        break;
                        case 2:
                            printf("%s ", dezenas[2]);
                        break;
                        case 3:
                            printf("%s ", dezenas[3]);
                        break;
                        case 4:
                            printf("%s ", dezenas[4]);
                        break;
                        case 5:
                            printf("%s ", dezenas[5]);
                        break;
                        case 6:
                            printf("%s%s ", dezenas[6], unidades[5]);
                        break;
                        case 7:
                            printf("%s%s ", dezenas[6], unidades[6]);
                        break;
                        case 8:
                            printf("%s%s ", dezenas[0], unidades[7]);
                        break;
                        case 9:
                            printf("%s%s%s ", dezenas[0], extra[0], unidades[8]);
                        break;
                    }
                break;
                case 2:
                    printf("%s ", dezenas[7]);
                break;
                case 3:
                    printf("%s ", dezenas[8]);
                break;
                case 4:
                    printf("%s ", dezenas[9]);
                break;
                case 5:
                    printf("%s ", dezenas[10]);
                break;
                case 6:
                    printf("%s ", dezenas[11]);
                break;
                case 7:
                    printf("%s%s ", unidades[6], dezenas[12]);
                break;
                case 8:
                    printf("%s ", dezenas[13]);
                break;
                case 9:
                    printf("%s%s ", unidades[8], dezenas[12]);
                break;
            }

            if((d != 0) && (d != 1) && (u != 0))
            {
                printf("%s ", extra [0]);
            }

            if(d != 1)
            {
                switch (u)
                {
                    case 1:
                        printf("%s ", unidades[0]);
                    break;
                    case 2:
                        printf("%s ", unidades[1]);
                    break;
                    case 3:
                        printf("%s ", unidades[2]);
                    break;
                    case 4:
                        printf("%s ", unidades[3]);
                    break;
                    case 5:
                        printf("%s ", unidades[4]);
                    break;
                    case 6:
                        printf("%s ", unidades[5]);
                    break;
                    case 7:
                        printf("%s ", unidades[6]);
                    break;
                    case 8:
                        printf("%s ", unidades[7]);
                    break;
                    case 9:
                        printf("%s ", unidades[8]);
                    break;
                }
            }

            if((m == 0) && (c == 0) && (d == 0) && (u == 1))
            {
                printf("%s ", extra[4]);
            }
            else
            {
                if((m == 0) && (c == 0) && (d == 0) && (u == 0))
                {
                    
                }
                else
                {
                    printf("%s ", extra[2]);
                }
            }

            if(((dec != 0) || (cent != 0)) && ((m != 0) || (c != 0) || (d != 0) || (u != 0)))
            {
                printf("%s ", extra [0]);
            }

            switch (dec)
            {
                case 1:
                    switch (cent)
                    {
                        case 0:
                            printf("%s ", dezenas[0]);
                        break;
                        case 1:
                            printf("%s ", dezenas[1]);
                        break;
                        case 2:
                            printf("%s ", dezenas[2]);
                        break;
                        case 3:
                            printf("%s ", dezenas[3]);
                        break;
                        case 4:
                            printf("%s ", dezenas[4]);
                        break;
                        case 5:
                            printf("%s ", dezenas[5]);
                        break;
                        case 6:
                            printf("%s%s ", dezenas[6], unidades[5]);
                        break;
                        case 7:
                            printf("%s%s ", dezenas[6], unidades[6]);
                        break;
                        case 8:
                            printf("%s%s ", dezenas[0], unidades[7]);
                        break;
                        case 9:
                            printf("%s%s%s ", dezenas[0], extra[0], unidades[8]);
                        break;
                    }
                break;
                case 2:
                    printf("%s ", dezenas[7]);
                break;
                case 3:
                    printf("%s ", dezenas[8]);
                break;
                case 4:
                    printf("%s ", dezenas[9]);
                break;
                case 5:
                    printf("%s ", dezenas[10]);
                break;
                case 6:
                    printf("%s ", dezenas[11]);
                break;
                case 7:
                    printf("%s%s ", unidades[6], dezenas[12]);
                break;
                case 8:
                    printf("%s ", dezenas[13]);
                break;
                case 9:
                    printf("%s%s ", unidades[8], dezenas[12]);
                break;
            }

            if((dec != 0) && (dec != 1) && (cent != 0))
            {
                printf("%s ", extra [0]);
            }

            if(dec != 1)
            {
                switch (cent)
                {
                    case 1:
                        printf("%s ", unidades[0]);
                    break;
                    case 2:
                        printf("%s ", unidades[1]);
                    break;
                    case 3:
                        printf("%s ", unidades[2]);
                    break;
                    case 4:
                        printf("%s ", unidades[3]);
                    break;
                    case 5:
                        printf("%s ", unidades[4]);
                    break;
                    case 6:
                        printf("%s ", unidades[5]);
                    break;
                    case 7:
                        printf("%s ", unidades[6]);
                    break;
                    case 8:
                        printf("%s ", unidades[7]);
                    break;
                    case 9:
                        printf("%s ", unidades[8]);
                    break;
                }
            }

            if((dec == 0) && (cent == 1))
            {
                printf("%s ", extra [5]);
            }
            else
            {
                if((dec != 0) || (cent != 0))
                {
                    printf("%s ", extra[3]);
                }
            }
        }
        
        printf("\nDigite um novo valor: ");
        scanf("%f", &n);

    }

    printf("\nOperacoes finalizadas.");
    
    return 0;
}

int *calcuni(float n)
{
    
    int aux1 = n, aux2;
    static int v[6];

    v[0] = n/1000; //milhares
    v[1] = n/100 - v[0]*10; //centenas
    v[2] = n/10 - (v[0]*100 + v[1]*10); //decimais
    v[3] = n - (v[0]*1000 + v[1]*100 + v[2]*10); //unidades
    aux2 = roundf((n - aux1) * 100);
    v[4] = aux2 / 10; //décimos
    v[5] = aux2 - v[4] * 10; //centésimos

    return (v);
}
