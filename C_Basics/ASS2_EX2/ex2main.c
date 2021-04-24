#include <stdio.h>

void check_Char(char x);

int main(void)
{
	while(1)
	{
		char x;
		printf("Enter an alphabet: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&x);
		check_Char( x);
	}
}

void check_Char(char x)
{
	int lower, upper;
	lower = (x == 'a' || x == 'e' || x == 'o' || x == 'u');
	upper = (x == 'A' || x == 'E' || x == 'O' || x == 'U');
	if( lower || upper)
	{
		printf("%c is a vowel", x);
		printf("\r\n");
	}else
	{
		printf("%c is a constant\r\n", x);
		printf("\r\n");
	}
}
