#include <stdio.h>
#define MAX_TERMS 101

struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {4.0, 3}, {3.0, 2}, {2.0, 1}, {1.0, 0}, {3.0, 2}, {2.0, 1},{8.0, 0 } };

int avail = 7;
int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;

void print_poly(int s, int e);

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
	printf("%3.1fx^%d + \n ", terms[e].coef, terms[e].expon);
}


