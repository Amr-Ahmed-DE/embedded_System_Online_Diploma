#include <stdio.h>

int main(void)
   {
	float x, y;
	printf("Enter two floating numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f", &x, &y);
	printf("sum: %f", x*y);
   }
