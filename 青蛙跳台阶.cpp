#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int in(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return in(n - 1) + in(n - 2);
}
int main()
{
	printf("����һ��Ҫ������̨����:");
	int n,m;
	scanf("%d", &n);
	m = in(n);
	printf("\n����һ����%d�ַ���", m);
	return 0;
}