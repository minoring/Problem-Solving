#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_power_of_two(int num)
{
	int temp = 2;
	while (num >= temp) {
		if (num == temp)
			return true;
		else
			temp *= 2;
	}
	return false;
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (b*b - 4*a*c > 0) {
		double root1 = (-b+sqrt((double)b*b-4*a*c))/(2*a);
		double root2 = (-b-sqrt((double)b*b-4*a*c))/(2*a);
		// printf("%f %f", root1 - (int)root1, root2 - (int)root2);
		printf("%d %d", 0 == root1 - (int)root1, 0 == root2 - (int)root2);
		if (root1-(int)root1 != 0 || root2-(int)root2 != 0) {
			printf("둘다틀렸근");
		} else if (is_power_of_two(root1) && is_power_of_two(root2)) {
			printf("이수근");
		} else {
			printf("정수근");
		}
	} else {
		printf("둘다틀렸근");
	}
	return 0;
}
