#include <stdio.h>

int main(void)
{
	float x, y, z;
	printf("Enter three numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f %f", &x, &y, &z);

	if(x > y && x > z)
	{
		printf("largest number = %f ", x);
	}else if (y > z && y > x)
	{
		printf("largest number = %f ", y);
	}else if(z > x && z > y)
	{
		printf("largest number = %f ", z);
	}
}
