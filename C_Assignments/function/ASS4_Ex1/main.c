#include <stdio.h>

int Check_PrimeNumber  (int Number);

int main (void)
{
	int Num1, Num2, i, flag;
	printf("Enter two numbers(interval):");
	fflush(stdin);fflush(stdout);
	scanf("%d %d", &Num1, &Num2);
	for(i = Num1; i< Num2;i++)
	{
		flag = Check_PrimeNumber(i);
		if(flag == 0)
			printf("%d,\t", i);
	}

}

int Check_PrimeNumber (int Number)
{
	int i;
	int flag = 0;

	for(i = 2; i <= Number/2; i++)
	{
		if(Number%i == 0)
		{
			flag = 1;
			break;
		}
	}

	return flag;
}
