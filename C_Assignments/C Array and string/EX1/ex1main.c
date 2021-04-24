/*Target:
 * get 2 matrices 2*2 from user and print sum of both matrices */

#include <stdio.h>

int main(void)
{
	float a[2][2]; //1st matrix
	float b[2][2]; //2nd matrix
	float c[2][2]; //sum matrix

	printf("enter the elements of 1st matrix\r\n");
	/*Loop to get operands of 1st matrix*/
	for(int i = 0; i <= 1;i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdout);fflush(stdin);
			scanf("%f", &a[i][j]);
		}
	}

	/*Loop to get operands of 2nd matrix*/
	printf("enter the elements of 2nd matrix\r\n");

	for(int i = 0; i <= 1;i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			printf("Enter b%d%d: ", i+1, j+1);
			fflush(stdout);fflush(stdin);
			scanf("%f", &b[i][j]);
		}
	}

	/*summation loop*/
	for(int i = 0; i <= 1;i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	/*print in console the result*/
	printf("Sum of matrix: \n");
	for(int i = 0; i <= 1;i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			printf("%.1f\t", c[i][j]);

			if(j == 1)
				printf("\n");
		}
	}
}
