#include<stdio.h>

void Check_char (char x);

int main(void)
{
	while(1)
	{
		char x;
		printf("Enter a character: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &x);
		Check_char(x);
	}
}

void Check_char(char x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		printf("%c is an alphabet\r\n", x);
	else
		printf("%c is not an alphabet\r\n", x);
}
