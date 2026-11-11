#include <iostream>

// TODO: Create the binary_search function
// Parameters: const int arr[], int size, int target
// Returns: int (index of target, or -1 if not found)
int binary_search(const int arr[], int size, int target);

int main() {
  // TODO: Create a sorted test array
  int arr[] = {1, 3, 5, 7, 9};

  // TODO: Calculate the size of the array
  int size{static_cast<int>(sizeof(arr) / sizeof(arr[0]))};

  // TODO: Call binary_search and print results
  binary_search(arr, size, 5);
  std::cout << "Binary search setup complete" << '\n';

  std::cout << "Testing with array:";
  for (int idx{0}; idx < size; ++idx) {
    std::cout << ' ' << arr[static_cast<std::size_t>(idx)];
  }

  return 0;
}

int binary_search(const int arr[], int size, int target) {
  int left{0};
  int right{size - 1};

  while (left <= right) {
    int mid{left + (right - left) / 2};

    break;
  }

  return -1;
}