#include <stdio.h>
#include<string.h>

int main(void)
{
 char string[100], freqchar;
 int i, sum = 0;

 printf("Enter a string: ");
 fflush(stdout); fflush(stdin);
 gets(string);

 printf("enter a character to find frequency: ");
 fflush(stdout); fflush(stdin);
 scanf("%c", &freqchar);

 for(i = 0; i < strlen(string); i++)
 {

	 if(string[i] == freqchar)
	 {
		 ++sum;
	 }
 }
 printf("frequency of %c = %d", freqchar, sum);
}
