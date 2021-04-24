#include <stdio.h>

int main(void)
{
	int n, i, e, array[10];
	printf("Enter no of elements: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		array[i] = (i+1) * 11;
	}

	for(i = 0; i < n; i++)
	{
		printf("%d\t", array[i]);
	}

	printf("\n enter the elements to be searched: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &e);

	for(i = 0; i < n - 1; i++)
	{
		if(array[i] == e)
		{
			printf("Number found at the location = %d", i+1);
		}
	}
}

