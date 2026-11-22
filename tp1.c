#include <stdio.h>

/*PARTIE 1 : suites U, V, W */

/* Prototypes (obligatoires pour la récursivité croisée) */
int U(int n);
int V(int n);
int W(int n);

int U(int n) {
    if (n == 0) return 1;
    return 2 * U(n - 1) + 3 * V(n - 1) + W(n - 1);
}

int V(int n) {
    if (n == 0) return 2;
    return U(n - 1) + V(n - 1) + 2 * W(n - 1);
}

int W(int n) {
    if (n == 0) return 3;
    return U(n - 1) + 4 * V(n - 1) + W(n - 1);
}

/* Même chose avec le type réel (question c) */
double Ur(int n);
double Vr(int n);
double Wr(int n);

double Ur(int n) {
    if (n == 0) return 1;
    return 2 * Ur(n - 1) + 3 * Vr(n - 1) + Wr(n - 1);
}

double Vr(int n) {
    if (n == 0) return 2;
    return Ur(n - 1) + Vr(n - 1) + 2 * Wr(n - 1);
}

double Wr(int n) {
    if (n == 0) return 3;
    return Ur(n - 1) + 4 * Vr(n - 1) + Wr(n - 1);
}

/* Version itérative (type réel) */
void suites_iter(int n) {
    double u = 1, v = 2, w = 3;
    double nu, nv, nw;
    int i;

    for (i = 1; i <= n; i++) {
        nu = 2 * u + 3 * v + w;
        nv = u + v + 2 * w;
        nw = u + 4 * v + w;
        u = nu;
        v = nv;
        w = nw;
    }
    printf("U(%d) = %.0f\nV(%d) = %.0f\nW(%d) = %.0f\n", n, u, n, v, n, w);
}

/* PARTIE 2 : Fibonacci*/

long long compteur = 0;   /* nombre d'appels récursifs */

/* Version récursive (type réel) */
double fib_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

/* Version récursive avec compteur d'appels (question g) */
double fib_rec_cpt(int n) {
    compteur++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_rec_cpt(n - 1) + fib_rec_cpt(n - 2);
}

/* Version itérative (deux variables pour les deux derniers termes) */
int fib_iter(int n) {
    int a = 0, b = 1, c, i;

    if (n == 0) return 0;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/*PROGRAMME PRINCIPAL  */

int main() {
    int choix, n, i;

    printf("=== TP1 : Recursivite \n");
    printf("1. Suites U,V,W recursives (entiers)\n");
    printf("2. Suites U,V,W recursives (reels)\n");
    printf("3. Suites U,V,W iteratives (reels)\n");
    printf("4. Fibonacci recursif (reels)\n");
    printf("5. Fibonacci recursif avec compteur d'appels\n");
    printf("6. Fibonacci iteratif\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix >= 1 && choix <= 3) {
        printf("Entrez n : ");
        scanf("%d", &n);
        if (choix == 1)
            printf("U=%d  V=%d  W=%d\n", U(n), V(n), W(n));
        else if (choix == 2)
            printf("U=%.0f  V=%.0f  W=%.0f\n", Ur(n), Vr(n), Wr(n));
        else
            suites_iter(n);
    }
    else if (choix == 4) {
        printf("Entrez n : ");
        scanf("%d", &n);
        printf("Fib(%d) = %.0f\n", n, fib_rec(n));
    }
    else if (choix == 5) {
        printf("Entrez n : ");
        scanf("%d", &n);
        compteur = 0;
        printf("Fib(%d) = %.0f\n", n, fib_rec_cpt(n));
        printf("Nombre d'appels : %lld\n", compteur);
    }
    else if (choix == 6) {
        printf("Entrez n : ");
        scanf("%d", &n);
        printf("Fib(%d) = %d\n", n, fib_iter(n));
        printf("Termes de 0 a 10 : ");
        for (i = 0; i <= 10; i++) printf("%d ", fib_iter(i));
        printf("\n");
    }
    else {
        printf("Choix invalide.\n");
    }
    return 0;
}
