#include <iostream>
#include <cstddef>
#include <stdexcept>

template<typename T, std::size_t N>
class StaticArray {
private:
  T m_data[N];

public:
  constexpr std::size_t size() const {
    return N;
  }

  T& operator[](std::size_t index) {
    return m_data[index];
  }

  const T& operator[](std::size_t index) const {
    return m_data[index];
  }

  T& at(std::size_t index) {
    if (index >= N) {
      throw std::out_of_range{"StaticArray index out of range"};
    }
    return m_data[index];
  }

  const T& at(std::size_t index) const {
    if (index >= N) {
      throw std::out_of_range{"StaticArray index out of range"};
    }
    return m_data[index];
  }

  // TODO: Add fill()
  void fill(T default_value) {
    for (size_t i {0}; i < N; ++i) {
      m_data[i] = default_value;
    }
  }

  // TODO: Add front() (non-const version)
  T& front() {
    return m_data[0];
  }
  // TODO: Add front() (const version)
  const T& front() const {
    return m_data[0];
  }
  // TODO: Add back() (non-const version)
  T& back() {
    return m_data[N - 1];
  }
  // TODO: Add back() (const version)
  const T& back() const {
    return m_data[N - 1];
  }
  // TODO: Add find()
  const int find(T value) const {
    for (std::size_t i {0}; i < N; ++i) {
      if (m_data[i] == value) {
        return i;
      }
    }

    return -1;
  }
};


int main() {
  StaticArray<int, 5> arr;

  // TODO: Call fill(0) and print "After fill(0):" followed by all elements
  arr.fill(0);
  std::cout << "After fill(0):";
  for (std::size_t i{0}; i < arr.size(); ++i) {
    std::cout << " " << arr[i];
  }
  std::cout << '\n';

  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  std::cout << "After setting values:";
  for (std::size_t i{0}; i < arr.size(); ++i) {
    std::cout << " " << arr[i];
  }
  std::cout << '\n';

  // TODO: Print "Front: " and "Back: " on the same line (e.g., "Front: 10, Back: 50")
  std::cout << "Front: " << arr.front() << ", Back: " << arr.back() << '\n';
  // TODO: Print "Index of 30: " and "Index of 99: " with find() results (on separate lines)
  std::cout << "Index of 30: " << arr.find(30) << '\n';
  std::cout << "Index of 99: " << arr.find(99) << '\n';
  return 0;
}
