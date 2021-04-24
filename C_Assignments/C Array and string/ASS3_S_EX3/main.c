#include<stdio.h>
#include<string.h>

int main(void)
{
	char string[100], Reverse[100];
	int i, j;

	printf("Enter the string: ");
	fflush(stdout); fflush(stdin);
	gets(string);

	for(i = strlen(string) - 1, j = 0; i >= 0 ; --i, ++j)
	{
    Reverse[j] = string[i];
	}
	Reverse[strlen(string)] = '\0';
	printf("Reverse string is: %s", Reverse);
}
