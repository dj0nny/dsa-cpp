#include <array>
#include <cstddef>
#include <iostream>

int linear_search(const int arr[], std::size_t size, int target);

// TODO: Convert the above function to a template that accepts std::array
// Use template<typename T, std::size_t N>
// Change parameters to const std::array<T, N>& arr, const T& target
// Use arr.size() instead of the separate size parameter
template <typename T, std::size_t N>
int linear_search(const std::array<T, N>& arr, const T& target) {
  for (std::size_t idx{0}; idx < arr.size(); ++idx) {
    if (arr[idx] == target) {
      return static_cast<int>(idx);
    }
  }

  return -1;
}

int main() {
  std::array<int, 6> numbers{10, 25, 8, 42, 17, 33};

  // TODO: Update to pass the array directly (no .data() or .size())
  std::cout << "Searching for 42: found at index " << linear_search(numbers, 42) << '\n';

  // TODO: Update to pass the array directly (no .data() or .size())
  std::cout << "Searching for 99: not found (" << linear_search(numbers, 99) << ")" << '\n';

  // TODO: Create a std::array<double, 4>: {19.99, 29.99, 39.99, 49.99}
  std::array<double, 4> prices{19.99, 29.99, 39.99, 49.99};
  // TODO: Search for 29.99 and print result
  std::cout << "Searching for 29.99: found at index " << linear_search(prices, 29.99) << '\n';
  // TODO: Search for 100.0 and print result
  std::cout << "Searching for 100.0: not found (" << linear_search(prices, 100.0) << ")";

  return 0;
}

int linear_search(const int arr[], std::size_t size, int target) {
  for (std::size_t idx{0}; idx < size; ++idx) {
    if (arr[idx] == target) {
      return static_cast<int>(idx);
    }
  }

  return -1;
}