/* Arquivo MAIN que usa o TAD racionais */
#include <stdio.h>
#include <stdlib.h>
#include "racionais.h"
#include <time.h>
/* coloque seus includes aqui */


int main (){
        int i, n, max;
        struct racional r1, r2, som, sbt, mul, div;

        srand(0);
        //srand(time(NULL));

        scanf( "%d %d" , &n, &max);

        for( i = 1; i <= n; i++) {
                printf("%d: ", i);

                r1 = sorteia_r(max);
                r2 = sorteia_r(max);

                imprime_r(r1);
                printf(" ");
                imprime_r(r2);
                printf(" ");

                if (r1.valido == 0 || r2.valido == 0) {
                        printf("NUMERO INVALIDO");
                        return 1;
                }
                som = soma_r(r1,r2);
                sbt = subtrai_r(r1, r2);
                mul = multiplica_r(r1, r2);
                div = divide_r(r1, r2);

                if (div.valido == 0) {
                        printf("DIVISAO INVALIDA");
                        return 1;
                }
                imprime_r(som);
                printf(" ");
                imprime_r(sbt);
                printf(" ");
                imprime_r(mul);
                printf(" ");
                imprime_r(div);
                printf(" ");
                printf("\n");
        }

        return 0;
}
