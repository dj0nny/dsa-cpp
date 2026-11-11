#include <iostream>

int binary_search(const int arr[], int size, int target);

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int size{static_cast<int>(sizeof(arr) / sizeof(arr[0]))};

  std::cout << "Testing with array:";
  for (int idx{0}; idx < size; ++idx) {
    std::cout << ' ' << arr[static_cast<std::size_t>(idx)];
  }

  // TODO: Test binary_search with different values
  // Search for: 7 (exists), 1 (first), 9 (last), 6 (not found)
  std::cout << "\nIndex of 7: " << binary_search(arr, size, 7) << '\n';
  std::cout << "Index of 1: " << binary_search(arr, size, 1) << '\n';
  std::cout << "Index of 9: " << binary_search(arr, size, 9) << '\n';
  std::cout << "Index of 6: " << binary_search(arr, size, 6) << '\n';

  return 0;
}

int binary_search(const int arr[], int size, int target) {
  int left{0};
  int right{size - 1};

  while (left <= right) {
    int mid{left + (right - left) / 2};

    // TODO: Check if arr[mid] equals target
    // If so, return mid (we found it!)
    if (arr[mid] == target) {
      return mid;

      // TODO: Check if arr[mid] is greater than target
      // If so, search the left half: right = mid - 1
    } else if (arr[mid] > target) {
      right = mid - 1;

      // TODO: Otherwise, search the right half
      // left = mid + 1
    } else {
      left = mid + 1;
    }
  }

  return -1;
}