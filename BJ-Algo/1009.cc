#include <cstdio>

int main() {
  int T, a, b;
  scanf("%d", &T);

  while (T--) {
    scanf("%d %d", &a, &b);

    int result = 1;
    // Accumulate number to module. ex) 5^1%19, 5^2%19 ...
    int accum = a;
    while (b > 0) {
      if (b & 1) {
        // If LSB is 1.
        result = (result*accum)%10;
      } 
      accum = (accum*accum)%10;
      b /= 2;
    }    

    result = (result == 0) ? 10 : result;
    printf("%d\n", result);
  } 
}
