#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, temp; cin >> n;
    long max = 0, min = 1000001;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }
    cout << max * min;
    return 0;
}

/* 모든 약수가 주어진 상태에서 원래의 n값을 찾아가는 문제이다.
   이문제의 키워드는 '모든'이다.

   예를들어 n == 30 이라면 주어지는 약수는 {2, 3, 5, 6, 10, 15} 이다.
   숫자 {2, 3, 5, 6, 10, 15} 이 주어졌을때, n이 30이라는걸 알아야 한다.
   자칫 잘못하면 문제를 이해 못하고 엉뚱한 방향으로 나갈수 있다. 
   ({2, 3, 5} 라고  주어졌을때 답을 30이라 한다던지... 이런경우는 없다.)
   
   해설. d가 n의 약수일때, n == (n / d) * d 로 표현할 수 있다.
   n이 작으면 작을수록 (n / d) 는 커지니까, 약수중 가장 작은값을 d라고
   한다면 약수중 가장 큰 값은 (n / d)가 된다. 
   따라서 n 은 약수중 가장 작은값 * 약수중 가장 큰 값이 된다.
*/