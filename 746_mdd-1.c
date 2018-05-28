#include <stdio.h>
#include <stdlib.h>
void comb(int *m,int g)
{	int tmp,k;
	int s=g; // готовим начальный шаг
	long long cnt=0;
	while(g>1) {
		s/=1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
                                        // и легкие элементы в хвосте переносятся в первые 20%
		if (s<1) s=1; // 0 быть не может, присвоим 1
		k=0; // нет перестановок
		for (int i=0; i+s<g;++i)
        { // двигаемся, пока сравниваемый элемент (на s от текущего) в массиве
			if(m[i]/10>m[i+s]/10) {
				tmp=m[i];
				m[i]=m[i+s];
				m[i+s]=tmp;
				k=i;
			}
			++cnt;
		}
		if (s==1) // шаг 1, как в обычном пузырьке. Включаем контроль
			g=k+1;
	}
}
int main ()
{
    int n, i,*mas;
    scanf("%d", &n);
    mas  =  (int *)calloc(n, sizeof(int));
    for (i = 0;i< n;i++)
    {
        scanf("%d", &mas[i]);
    }
    comb(mas,n);
    for(i = 0;i < n;i++)
    {
        printf("%d ", (mas[i]));
    }
    return 0;
}
