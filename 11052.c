#include <stdio.h>
int Max(int a, int b) { return a > b ? a : b; }
int main() {
	int n, d[1001] = {0}, p[1001];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			d[i] = Max(d[i], d[i - j] + p[j]);
	printf("%d", d[n]);
	return 0;
}
