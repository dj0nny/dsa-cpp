#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

int linear_search(const int arr[], std::size_t size, int target);

template <typename T, std::size_t N>
int linear_search(const std::array<T, N>& arr, const T& target) {
  for (std::size_t idx{0}; idx < arr.size(); ++idx) {
    if (arr[idx] == target) {
      return static_cast<int>(idx);
    }
  }

  return -1;
}

// TODO: Implement find_all()
// Returns std::vector<int> containing all indices where target is found
// Parameters: const std::array<T, N>& arr, const T& target
template <typename T, std::size_t N>
std::vector<int> find_all(const std::array<T, N>& arr, const T& target) {
  std::vector<int> indexes{};

  for (std::size_t idx{0}; idx < arr.size(); ++idx) {
    if (arr[idx] == target) {
      indexes.push_back(static_cast<int>(idx));
    }
  }

  return indexes;
}

// TODO: Implement find_if()
// Returns index of first element where pred(element) is true, or -1
// Parameters: const std::array<T, N>& arr, Predicate pred
template <typename T, std::size_t N, typename Predicate>
int find_if(const std::array<T, N>& arr, Predicate pred) {
  for (std::size_t idx{0}; idx < arr.size(); ++idx) {
    if (pred(arr[idx])) {
      return static_cast<int>(idx);
    }
  }

  return -1;
}

// TODO: Implement count()
// Returns std::size_t count of how many elements equal target
// Parameters: const std::array<T, N>& arr, const T& target
template <typename T, std::size_t N>
std::size_t count(const std::array<T, N>& arr, const T& target) {
  std::size_t counter{};
  for (std::size_t idx{0}; idx < arr.size(); ++idx) {
    if (arr[idx] == target) {
      ++counter;
    }
  }

  return counter;
}

template <typename T, std::size_t N>
bool contains(const std::array<T, N>& arr, const T& target) {
  return linear_search(arr, target) != -1;
}

template <typename T, std::size_t N>
int find_last(const std::array<T, N>& arr, const T& target) {
  // loop backwards from the last index to 0
  for (int idx{static_cast<int>(arr.size() - 1)}; idx >= 0; --idx) {
    // if the element matches the target, return the index
    if (arr[static_cast<std::size_t>(idx)] == target) {
      return idx;
    }
  }

  // return -1 if not found
  return -1;
}

int main() {
  std::array<int, 6> numbers{10, 25, 8, 42, 17, 17};

  std::cout << "Searching for 42: found at index " << linear_search(numbers, 42) << '\n';
  std::cout << "Searching for 99: not found (" << linear_search(numbers, 99) << ")" << '\n';

  std::array<double, 4> prices{19.99, 29.99, 39.99, 49.99};

  std::cout << "Searching for 29.99: found at index " << linear_search(prices, 29.99) << '\n';
  std::cout << "Searching for 100.0: not found (" << linear_search(prices, 100.0) << ")" << '\n';

  // TODO: Test find_all() with numbers array - find all indices of 42
  // Expected output: "All indices of 42: 3"
  std::vector<int> indexes{find_all(numbers, 42)};
  std::cout << "All indices of 42: ";
  for (const auto& item : indexes) {
    std::cout << item;
  }

  // TODO: Test find_if() - find first value > 30
  // Expected output: "First value > 30: 42 at index 3"
  auto predicate{[](int x) { return x > 30; }};

  std::cout << "\nFirst value > 30: 42 at index " << find_if(numbers, predicate) << '\n';

  // TODO: Test count() - count occurrences of 17
  // Expected output: "Count of 17: 2"
  std::cout << "Count of 17: " << count(numbers, 17) << '\n';

  // TODO: Create a scores array with duplicates: {85, 92, 78, 85, 90, 85}
  std::array<int, 6> scores{85, 92, 78, 85, 90, 85};
  // TODO: Use find_all() to find all indices of 85
  // Expected output: "All indices of 85: 0 3 5"
  indexes = find_all(scores, 85);
  std::cout << "All indices of 85:";
  for (const auto& item : indexes) {
    std::cout << ' ' << item;
  }

  // TODO: Use count() to count occurrences of 85
  // Expected output: "Count of 85: 3"
  std::cout << "\nCount of 85: " << count(scores, 85);

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