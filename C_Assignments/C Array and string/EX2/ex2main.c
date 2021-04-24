/*Target:
 * get n number of elements from user and calculate the average*/

#include <stdio.h>

int main(void)
{
	int n = 0;
	int i;
	float a[50];
	float sum = 0;
	/*get how many values will be entered*/
	printf("Enter the numbers of data max 50: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &n);

	/*get numbers from user*/
	for(i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i+1);
		fflush(stdout);fflush(stdin);
		scanf("%f",&a[i]);
	}
	/*calculate and print average*/
	for(i = 0; i < n; i++)
	{
		sum+= a[i];
	}
	printf("average = %.2f", sum/n);
}
