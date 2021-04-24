#include<stdio.h>

int main(void)
{
	int matrix[5][5], transpose[5][5];
	int r,c,i,j;

	printf("Enter rows and columns of matrix max 5*5: ");
	fflush(stdout); fflush(stdin);
	scanf("%d %d", &r, &c);

	/*fill matrix by user*/
	printf("enter elements of the matrix: \n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("enter elements a%d%d: ", i+1, j+1);
			fflush(stdout); fflush(stdin);
			scanf("%d", &matrix[i][j]);
		}
	}

	/*print the entered matrix*/
	printf("Entered Matrix:\n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d\t", matrix[i][j]);
			if(j == c - 1)
				printf("\n");
		}
	}

	/*transpose the entered matrix*/
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			transpose[j][i] = matrix[i][j];
		}
	}

	/*print the transpose matrix*/
	printf("transpose of Matrix:\n");
	for(i = 0; i < c; i++)
	{
		for(j = 0; j < r; j++)
		{
			printf("%d\t", transpose[i][j]);
			if(j == r - 1)
				printf("\n");
		}
	}

}
