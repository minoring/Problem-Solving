#include <algorithm>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int smaller_num;
    int larger_num;
    std::cin >> smaller_num >> larger_num;
    if (smaller_num > larger_num) {
        std::swap(smaller_num, larger_num);
    }

    int round_count = 1;
    while (1) {
        if (smaller_num % 2 == 1 && smaller_num + 1 == larger_num) {
            break;
        }
        smaller_num = (smaller_num / 2) + ((smaller_num % 2 == 1) ? 1 : 0);
        larger_num = (larger_num / 2) + ((larger_num % 2 == 1) ? 1 : 0);
        ++round_count;
    }
    std::cout << round_count << '\n';
}