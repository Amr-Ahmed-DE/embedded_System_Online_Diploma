#include <stdio.h>

int main(void)
{
	unsigned int x, sum = 0;
	int i = 0;

	printf("please enter a positive integer:");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &x);

	while(i <= x)
	{
		sum+= i;
		i++;
	}
	printf("sum = %u", sum);
}
