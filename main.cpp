#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

template <typename T, typename U>
void fisher_yates_shuffle(std::vector<T> &toShuffle, U &&rng) {
  for (size_t i = toShuffle.size() - 1; i >= 1; i--) {
    const auto j = rng() % i;
    std::swap(toShuffle[i], toShuffle[j]);
  }
}

int main() {
  std::mt19937 random_engine{};
  random_engine.seed(0);

  {
    std::vector<size_t> vec(50);
    std::iota(vec.begin(), vec.end(), 0);

    fisher_yates_shuffle(vec, random_engine);
    std::cout << "Fisher-Yates from mt19937\n";
    for (const auto el : vec) {
      std::cout << el << ' ';
    }
    std::cout << '\n';
  }

  {
    std::vector<size_t> vec(50);
    std::iota(vec.begin(), vec.end(), 0);
    std::shuffle(vec.begin(), vec.end(), random_engine);

    std::cout << "std::shuffle from mt19937\n";
    for (const auto el : vec) {
      std::cout << el << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
