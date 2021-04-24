#include <stdio.h>

void Calculator(float FirstNumber, float SecondNumber, char operation);

int main(void)
{
	char x;
	float a, b;
	while(1)
	{
		printf("please enter Operation + , - , * or / :");
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &x);
		printf("please enter two Operands = ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f %f", &a, &b);

		Calculator(a, b, x);
	}
}
void Calculator(float FirstNumber, float SecondNumber, char operation)
{
	float sum = 0;

	switch (operation)
	{
	case '+' :
	{
		sum = FirstNumber + SecondNumber;
		printf("Result = %f\r\n", sum);
		break;
	}
	case '-' :
	{
		sum = FirstNumber - SecondNumber;
		printf("Result = %f\r\n", sum);
		break;
	}
	case '*' :
		{
			sum = FirstNumber * SecondNumber;
			printf("Result = %f\r\n", sum);
			break;
		}
	case '/' :
		{
			sum = FirstNumber - SecondNumber;
			printf("Result = %f\r\n", sum);
			break;
		}
	}
}
