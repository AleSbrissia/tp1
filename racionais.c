#include "racionais.h"
#include <stdio.h>   /* acrescente demais includes que voce queira ou precise */
#include <sdtlib.h>

struct racional {
        unsigned short int valido;
        int num;
        int den;
};

int mdc(int a, int b) {

        int c;
        c = a;

        while( c != 0) {

          c = a % b;
          a = b;
          b = c;
        }

        return a;
}
int valido_r( struct racional r) {

        if (r.den == 0) return 0;
        return 1;
}

struct racional criar_r( int numerador, int denominador) {

        struct racional n;

        n.num = numerador;
        n.den = denominador;
        n.valido = valido_r(n);

        return n;
}
struct racional simplifica_r( struct racional r) {

        int d;

        if (r.valido == 1) {

                if ((r.num < 0 && r.den < 0) || (r.num >= 0 && r.den < 0)) { //casos que r eh multiplicado po -1/-1
                        r.den *= -1;
                        r.num *= -1;
                }
                if ( r.num != 0) { //simplifica por mdc
                        d = mdc(r.num, r.den);
                        r.num /= d;
                        r.den /= d;
                }
                return r;
        }
        return r; /*caso nao seja valido, r eh devolvido sem modificacao */
}

int aleat(int min, int max) {

        int n;

        srand(0);

        n = rand() % max; //garante que min < n < max
        n += min;

        return n;
}
