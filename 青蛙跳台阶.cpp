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
	printf("青蛙一共要跳几级台阶呢:");
	int n,m;
	scanf("%d", &n);
	m = in(n);
	printf("\n青蛙一共有%d种方法", m);
	return 0;
}