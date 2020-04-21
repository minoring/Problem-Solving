#include <iostream>
#include <algorithm>

int main() {
  int min_burger;
  std::cin >> min_burger;

  int temp;
  std::cin >> temp;
  min_burger = std::min(min_burger, temp);
  std::cin >> temp;
  min_burger = std::min(min_burger, temp);

  int min_drink;
  std::cin >> min_drink;
  std::cin >> temp;
  min_drink = std::min(min_drink, temp);

  std::cout << min_burger + min_drink - 50 << '\n';
}