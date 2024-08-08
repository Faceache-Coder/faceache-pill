#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int p[19], i = 0;
	for (i = 0; i < 19; i++)
	{
		p[i] = i;
	}
	int l = 0, r = 18, m = 9, k;
	printf("请输入想要找的数字:");
	scanf("%d", &k);
	while (l <= r)
	{
		m = (l + r) / 2;
		if (p[m] < k)
		{
			l = m + 1;

		}
		else if (p[m] > k)
		{
			r = m - 1;

		}
		else
		{
			printf("get it!");
			break;
		}
	}
	if (l > r)
		printf("pity!");
	return  0;
}