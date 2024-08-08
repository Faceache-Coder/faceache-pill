#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void sort(int arr[],int sz)
{
	int i,j,t;
	for (i = 0; i < sz-1; i++)
	{
		for (j = 0; j <sz-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}

}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int i,sz;
	sz = sizeof(arr)/sizeof(arr[0]);
	sort(arr,sz);
	for (i = 0; i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}