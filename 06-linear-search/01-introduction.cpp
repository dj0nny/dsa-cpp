#include <array>
#include <cstddef>
#include <iostream>

// TODO: Create the linear_search function
// Parameters: const int arr[], std::size_t size, int target
// Returns: int (index if found, -1 if not found)
int linear_search(const int arr[], std::size_t size, int target);

int main() {
  std::array<int, 6> numbers{10, 25, 8, 42, 17, 33};

  // TODO: Search for 42 and print the result
  std::cout << "Searching for 42: found at index " << linear_search(numbers.data(), numbers.size(), 42) << '\n';

  // TODO: Search for 99 and print the result
  std::cout << "Searching for 99: not found (" << linear_search(numbers.data(), numbers.size(), 99) << ")";

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