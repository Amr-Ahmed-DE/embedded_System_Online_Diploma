//program to swap two float numbers
//Eng: Amr Ahmed

#include <stdio.h>

void swap(float *a, float *b);

int main(void)
   {
	float x, y;
	printf("Enter value of a: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &x);

	printf("Enter value of b: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &y);
    swap(&x, &y);

	printf("After swapping, value of a = %f \n", x);
	printf("After swapping, value of b = %f", y);
   }
void swap(float *a, float *b)
    {
	float t;

	t  = *a;
	*a = *b;
	*b =  t;
	}
