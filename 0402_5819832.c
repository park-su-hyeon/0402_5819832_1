#include <stdio.h>

#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
};

struct term terms[MAX_TERMS] = {
    {4.0, 3}, {3.0, 2}, {2.0, 1}, {1.0, 0},
    {3.0, 2}, {2.0, 1}, {8.0, 0}
};

int avail = 7;

void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    int i, j, k;
    float coefficient;
    int exponent;

    // Initialize the result polynomial
    struct term result[MAX_TERMS];
    int resIndex = 0;

    // Multiply each term of polynomial A with each term of polynomial B
    for (i = As; i <= Ae; i++) {
        for (j = Bs; j <= Be; j++) {
            coefficient = terms[i].coef * terms[j].coef;
            exponent = terms[i].expon + terms[j].expon;

            // Search if the term with same exponent already exists in result
            for (k = 0; k < resIndex; k++) {
                if (result[k].expon == exponent) {
                    result[k].coef += coefficient;
                    break;
                }
            }

            // If no term with same exponent exists, add the term to result
            if (k == resIndex) {
                result[resIndex].coef = coefficient;
                result[resIndex].expon = exponent;
                resIndex++;
            }
        }
    }

    // Copy the result polynomial back to terms array
    for (i = 0; i < resIndex; i++) {
        terms[avail++] = result[i];
    }

    // Update pointers for the result polynomial
    *Cs = Ae + Bs;
    *Ce = Ae + Be;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main() {
    int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;

    poly_multiply(As, Ae, Bs, Be, &Cs, &Ce);


    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("___________________\n");
    print_poly(Cs, Ce);

    return 0;
}
