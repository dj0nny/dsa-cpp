#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray {
 private:
  T m_data[N];

 public:
  constexpr std::size_t size() const { return N; }

  // TODO: Add operator[] (non-const version)
  T& operator[](std::size_t index) { return m_data[index]; }
  // TODO: Add operator[] (const version)
  const T& operator[](std::size_t index) const { return m_data[index]; }
  // TODO: Add at() (non-const version)
  T& at(std::size_t index) {
    if (index >= N) throw std::out_of_range("Invalid StaticArray access.");

    return m_data[index];
  }
  // TODO: Add at() (const version)
  const T& at(std::size_t index) const {
    if (index >= N) throw std::out_of_range("Invalid StaticArray access.");

    return m_data[index];
  }
};

int main() {
  StaticArray<int, 5> arr;

  std::cout << "StaticArray size: " << arr.size() << '\n';

  // TODO: Set elements arr[0] through arr[4] to values 10, 20, 30, 40, 50
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;
  // TODO: Print "After setting values:" followed by all elements in a loop
  std::cout << "After setting values:";
  for (std::size_t i{0}; i < arr.size(); ++i) std::cout << ' ' << arr.at(i);

  // std::cout << arr.at(-1) << ' ';
  // std::cout << arr.at(10) << ' ';

  return 0;
}
