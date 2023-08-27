#include "racionais.h"
#include <stdio.h>   /* acrescente demais includes que voce queira ou precise */
#include <stdlib.h>
#include <time.h>

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
int mmc( int a, int b) {

        int n, r, den;

        n = (a * b);
        den = mdc(a, b);
        r = n / den;


        return r;
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

/* as entradas min e max devem ser > 0 */
int aleat(int min, int max) {

        int n;
        n = rand() % max; //garante que min < n < max
        n += min;

        return n;
}
struct racional sorteia_r (int n) {

        int den, num;
        struct racional r;

        den = aleat( 0, n);
        num = aleat( 0, n);

        r = criar_r(num, den);

        r = simplifica_r( r );

        return r;
}

struct racional soma_r(struct racional r1, struct racional r2) {
        struct racional s;

        if ( r1.valido == 1 && r2.valido == 1) {
                s.den = mmc(r1.den, r2.den);

                r1.num = (s.den / r1.den) * r1.num;
                r2.num = (s.den / r2.den) * r2.num;

                s.num = r1.num + r2.num;
                s.valido = valido_r(s);
                s = simplifica_r(s);
                return s;
        }
        s.num = 0; //caso um numero nao seja valido, s eh invalidado
        s.den = 0;
        s.valido = 0;
        return s;
}

struct racional subtrai_r(struct racional r1, struct racional r2) {

        struct racional sb;

        r2.num *= -1;
        sb = soma_r(r1, r2);
        return sb;
}

struct racional multiplica_r(struct racional r1, struct racional r2) {

        struct racional m;

        m.num = r1.num * r2.num;
        m.den = r1.den * r2.den;
        m.valido = valido_r(m);
        m = simplifica_r(m);
        return m;
}

struct racional divide_r(struct racional r1, struct racional r2) {

        int t;
        struct racional d;

        if (r1.valido == 1 && r2.valido == 1) {
                t = r2.den; //inverto o numerador e denominador de r2
                r2.den = r2.num;
                r2.num = t;
                d = multiplica_r(r1, r2);
                d = simplificar_r(d);
                return d;
        }
        d.num = 0;
        d.den = 0;
        d.valido = 0;
        return d;
}

void imprime_r(struct racional r) {
        if (r.valido == 0) printf( "INVALIDO");
        if (r.valido == 1) {
                if (r.num == 0) printf("0");
                if (r.den == 1 && r.num != 0) printf( "%d", r.num);
                if (r.den != 1 && r.num != 0) printf( "%d/%d", r.num, r.den);
        }
}



















