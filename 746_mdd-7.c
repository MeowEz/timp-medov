#include <stdio.h>
#include <malloc.h>

void SortRasch(int a[], int nElements)
{
	int i, b, shag, swapped = 1;
	double temp;

	shag = nElements;
	while (shag > 1 || swapped == 1)
	{
		shag = shag * 10 / 13;
		if (shag == 9 || shag == 10) shag = 11;
		if (shag < 1) shag = 1;
		swapped = 0;
		for (i = 0, b = shag; b < nElements; i++, b++)
		{
			if (a[i] > a[b])
			{
				temp = a[i];
				a[i] = a[b];
				a[b] = temp;
				swapped = 1;
			}
		}
	}
}

int main()
{
	int nElements;
	scanf("%d", &nElements);
	int* mass;
	mass = (int *)malloc(nElements * sizeof(int));
	for (int i = 0; i < nElements; i++)
		scanf("%d", &mass[i]);

	SortRasch(mass, nElements);
	for (int i = 0; i < nElements; i++)
		printf("%d ", mass[i]);
	printf("\n");
	free(mass);
	return 0;
}
