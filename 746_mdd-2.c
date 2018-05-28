#include <stdio.h>

void main() {
	int n, i, x1, err = 0, x2;
	scanf("%d\n", &n);
	scanf("%d\n", &x1);
	for (i = 1; i<n; i++) {
		scanf("%d", &x2);
		if (x2<x1) { err++; }
		x1 = x2;
	}
	if (err == 0) { printf("1\n"); }
	else { printf("0\n"); };
}