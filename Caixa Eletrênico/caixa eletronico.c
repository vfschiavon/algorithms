#include <stdio.h>
int main (){
    int s, vt, n50, n20, i50, i20, q50, q20, r50, r20, qr5020, rr5020;  
    printf("Insira a quantidade inicial de cedulas de 50: ");
    scanf("%d", &i50);
    printf("Inisra a quantidade inicial de cedulas de 20: ");
    scanf("%d", &i20);
    printf("Digite o valor a ser sacado: ");
    scanf("%d", &s);
    
    while(s!=0){
        vt=50*i50+20*i20;
        n50=0;
        n20=0;
        if(s>vt){
            printf("Nao ha saldo suficiente para compor o saque.");
        }else{
            q50=s/50;
            r50=s%50;
            qr5020=r50/20;
            rr5020=r50%20;
            q20=s/20;
            r20=s%20;
            if(r50==0){
                n50=q50;
                if((n50>i50) && (r20==0) && (n20<=q20)){
                    n50=0;
                    n20=q20;
                }
            }else{
                if(q50>=1){
                    n50=q50;
                    n20=qr5020;
                    if((rr5020!=0) && (r20==0)){
                        n50=0;
                        n20=q20;
                    }
                }else{
                    if(q20>=1){
                        n20=q20;
                    }
                }
            }
        }
        if((n50*50+n20*20==s) && (n20<=i20) && (n50<=i50)){
            printf("%d cedula(s) de 50 e %d cedula(s) de 20.", n50, n20);
            i50=i50-n50;
            i20=i20-n20;
        }else{
            if((n50!=0) || (n20!=0)){
                printf("Nao existem cedulas para compor o valor solicitado.");
            }
        }
        printf("\nEscreva o novo valor a ser sacado: ");
        scanf("%d", &s);
    }
    printf("Operacoes finalizadas.");
    
    return 0;
}