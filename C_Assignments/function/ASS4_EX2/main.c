#include <stdio.h>

int factorial(int number);

int main(void)
{
	int num;
	printf("Enter an positive integer");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num);
	int y = factorial(num);
	printf("Factorial of %d = %d", num, y);
}

int factorial(int number)
{
	if(number >= 1)
		return number*factorial(number-1);
	else
		return 1;
}
