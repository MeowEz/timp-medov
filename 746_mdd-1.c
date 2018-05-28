#include <stdio.h>
#include <stdlib.h>
void comb(int *m,int g)
{	int tmp,k;
	int s=g; // ������� ��������� ���
	long long cnt=0;
	while(g>1) {
		s/=1.247f; // ��� �� ���� �������.  �� ������ ������� ���������� �������� 80% �� ������� �������,
                                        // � ������ �������� � ������ ����������� � ������ 20%
		if (s<1) s=1; // 0 ���� �� �����, �������� 1
		k=0; // ��� ������������
		for (int i=0; i+s<g;++i)
        { // ���������, ���� ������������ ������� (�� s �� ��������) � �������
			if(m[i]/10>m[i+s]/10) {
				tmp=m[i];
				m[i]=m[i+s];
				m[i+s]=tmp;
				k=i;
			}
			++cnt;
		}
		if (s==1) // ��� 1, ��� � ������� ��������. �������� ��������
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
