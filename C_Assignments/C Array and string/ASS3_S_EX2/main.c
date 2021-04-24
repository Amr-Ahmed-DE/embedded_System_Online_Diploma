#include <stdio.h>

int main(void)
{
	char String[100];
	int i = 0;
	printf("Enter a string: ");
    fflush(stdout); fflush(stdin);
    scanf("%s", String);

    while(String[i] != '\0')
    {
    	i++;
    }
    if(i > 0)
    {
    	printf("length of string = %d", i);
    }else
    {
    	printf("Enter correct string");
    }


}
