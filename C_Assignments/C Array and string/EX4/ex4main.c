#include <stdio.h>

int main(void)
{
	int n, i, e, index, matrix[10];
	printf("Enter no of elements max 10: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		matrix[i] = i+1;
	}
	for(i = 0; i < n; i++)
	{
		printf("%d\t", matrix[i]);
	}

	printf("\nEnter the element to be inserted: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &e);

	printf("Enter the location: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &index);

	for(i = n; i >= index; i--)
	{
		matrix[i] = matrix[i - 1];
	}

	matrix[index -1] = e;

	for(i = 0; i < n+1; i++)
	{
		printf("%d\t", matrix[i]);
	}

}
