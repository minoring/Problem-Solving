#include <iostream>

int DivSum(int x) {
    int temp = x;
    while (temp > 0) {
        x += temp % 10;
        temp /= 10;
    }
    return x;
}

int main() {
    int N;
    std::cin >> N;

    bool found = false;
    for (int i = 0; i <= N; ++i) {
        if (DivSum(i) == N) {
            found = true;
            std::cout << i << '\n';
            break;
        }
    }
    if (!found) {
        std::cout << 0 << '\n';
    }
}
