#include <stdio.h>
int main(void) {
	int testCase;
	scanf("%d", &testCase);
	while(testCase--) {
		unsigned int numStudent, numOverAver = 0, sum = 0;
		int average;
		int score[1000];
		double result;
		scanf("%d", &numStudent);
		for(int i = 0; i < numStudent; ++i) {
			scanf("%d", &score[i]);
			sum += score[i];
		}
		average = sum / numStudent;
		for(int i = 0; i < numStudent; ++i) {
			if(score[i] > average)
				numOverAver++;
		}
		result = ((double)numOverAver / numStudent) * 100;
		printf("%.3lf%%\n", result);
	}
	return 0;
}