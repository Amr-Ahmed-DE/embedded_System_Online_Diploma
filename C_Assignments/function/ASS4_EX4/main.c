#include <stdio.h>

int power_Number(int base, int power);
int main(void)
{
	int base, power;
 printf("Enter base number: ");
 fflush(stdin); fflush(stdout);
 scanf("%d", &base);
 printf("enter power number: ");
 fflush(stdin); fflush(stdout);
 scanf("%d", &power);

 printf("equal= %d", power_Number(base,  power));
}

int power_Number(int base, int power)
{
	if(power > 0)
		return (base * power_Number(base, power -1));
	else
		return 1;
}
