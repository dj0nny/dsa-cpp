#include <iostream>

int binary_search(const int arr[], int size, int target);

// TODO: Implement binary_search_recursive
// Parameters: const int arr[], int left, int right, int target
// Base case: if left > right, return -1
// Recursive case: compare arr[mid] and make recursive call
int binary_search_recursive(const int arr[], int left, int right, int target);

// TODO: Implement lower_bound
// Returns index of first element >= target
// If no such element exists, return size
int lower_bound(const int arr[], int size, int target);

// TODO: Implement upper_bound
// Returns index of first element > target
// If no such element exists, return size
int upper_bound(const int arr[], int size, int target);

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int size{static_cast<int>(sizeof(arr) / sizeof(arr[0]))};

  std::cout << "Testing with array:";
  for (int idx{0}; idx < size; ++idx) {
    std::cout << ' ' << arr[static_cast<std::size_t>(idx)];
  }

  std::cout << "\nIndex of 7: " << binary_search(arr, size, 7) << '\n';
  std::cout << "Index of 1: " << binary_search(arr, size, 1) << '\n';
  std::cout << "Index of 9: " << binary_search(arr, size, 9) << '\n';
  std::cout << "Index of 6: " << binary_search(arr, size, 6) << '\n';

  // TODO: Test recursive binary search
  std::cout << "Recursive search for 5: " << binary_search_recursive(arr, 0, size, 5) << '\n';

  // TODO: Test lower_bound and upper_bound
  std::cout << "lower_bound(5): " << lower_bound(arr, size, 5) << '\n';
  std::cout << "upper_bound(5): " << upper_bound(arr, size, 5) << '\n';
  std::cout << "lower_bound(4): " << lower_bound(arr, size, 4) << '\n';
  std::cout << "upper_bound(4): " << upper_bound(arr, size, 4) << "\n\n";

  // TODO: Range query with duplicate array
  int arr2[]{1, 3, 5, 5, 5, 7, 9};
  int size2{sizeof(arr2) / sizeof(arr2[0])};

  std::cout << "Elements between 3 and 9 (exclusive): " << (lower_bound(arr2, size2, 9) - upper_bound(arr2, size2, 3)) << "\n\n";

  // TODO: Compare linear vs binary search counting
  int linear_count{0};
  for (int i{0}; i < size2; ++i) {
    if (arr2[i] == 5) {
      ++linear_count;
    }
  }
  std::cout << "Linear count of 5s: " << linear_count << " (visited all " << size2 << " elements)" << '\n';

  int bs_count{upper_bound(arr2, size2, 5) - lower_bound(arr2, size2, 5)};
  std::cout << "Binary search count of 5s: " << bs_count << " (2 searches of ~log2(" << size2 << ") steps)" << '\n';

  return 0;
}

int binary_search(const int arr[], int size, int target) {
  int left{0};
  int right{size - 1};

  while (left <= right) {
    int mid{left + (right - left) / 2};

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      right = mid - 1;

    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int binary_search_recursive(const int arr[], int left, int right, int target) {
  if (left > right) {
    return -1;
  }

  int mid{left + (right - left) / 2};

  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] > target) {
    return binary_search_recursive(arr, left, mid - 1, target);
  } else {
    return binary_search_recursive(arr, mid + 1, right, target);
  }
}

int lower_bound(const int arr[], int size, int target) {
  for (int idx{0}; idx < size; ++idx) {
    if (arr[idx] >= target) {
      return idx;
    }
  }

  return size;
}

int upper_bound(const int arr[], int size, int target) {
  for (int idx{0}; idx < size; ++idx) {
    if (arr[idx] > target) {
      return idx;
    }
  }

  return size;
}