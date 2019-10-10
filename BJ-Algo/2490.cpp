#include <iostream>
#include <string>

int main() {
    for (int t = 0; t < 3; ++t) {
        int zero_count = 0;
        int one_count = 0;
        for (int i = 0; i < 4; ++i) {
            int input_temp;
            std::cin >> input_temp;
            if (input_temp == 1)
                ++one_count;
            else
                ++zero_count;
        }
        std::string res = "DCBAE";
        std::cout << res[one_count] << '\n';
    }
}