#include <stdio.h>
#include <stdlib.h>
void quickSort(int *numbers, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int N;
	scanf("%d", &N);
	int* mass;
	mass = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		scanf("%d", &mass[i]);

	quickSort(mass, 0, N - 1);
	for (int i = 0; i <N; i++)
		printf("%d ", mass[i]);
	printf("\n");
	free(mass);
	return 0;
}

