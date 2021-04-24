#include <stdio.h>

void reverse();

int main(void)
{
	printf("enter a sentence: ");
	fflush(stdin); fflush(stdout);
	reverse();
}

void reverse ()
{
	char c;
	scanf("%c", &c);
	if(c != '\n')
	{
		reverse();
		printf("%c", c);

	}
}
