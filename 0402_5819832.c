#include <stdio.h>
#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = {{ 4.0, 3 }, { 3.0, 2 }, { 2.0, 1 }, { 1.0, 0 }, { 3.0, 2 }, { 2.0, 1 }, { 8.0, 0 }};

int avail = 7;
int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;

void print_poly(int s, int e);
void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce);

int main(int argc, char* argv[]) {

    poly_multiply(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("---------------------\n");
    print_poly(Cs, Ce);

    return 0;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++)
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    printf("%3.1fx^%d + \n", terms[e].coef, terms[e].expon);
}

void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    int i, j, k;
    float temp_coef;
    *Cs = avail;
    for (i = As; i <= Ae; i++) {
        for (j = Bs; j <= Be; j++) {
            temp_coef = terms[i].coef * terms[j].coef;
            int temp_expon = terms[i].expon + terms[j].expon;
            // Check if the term with the same exponent already exists in result polynomial
            for (k = *Cs; k <= *Ce; k++) {
                if (terms[k].expon == temp_expon) {
                    terms[k].coef += temp_coef;
                    break;
                }
            }
            // If term with same exponent doesn't exist, add a new term
            if (k > *Ce) {
                terms[avail].coef = temp_coef;
                terms[avail].expon = temp_expon;
                (*Ce)++;
                avail++;
            }
        }
    }
}
