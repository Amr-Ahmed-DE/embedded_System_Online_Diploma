#include <stdio.h>

int main(void)
   {
	int x, y;
	printf("Enter two integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d", &x, &y);
	printf("sum: %d", x+y);
   }
