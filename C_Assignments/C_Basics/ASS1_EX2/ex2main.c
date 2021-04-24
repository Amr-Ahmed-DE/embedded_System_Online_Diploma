#include <stdio.h>

int main(void)
   {
	int x;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &x);
	printf("You entered: %d",x);
   }
