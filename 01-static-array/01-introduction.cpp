#include <cstddef>
#include <iostream>
#include <stdexcept>

// TODO: Create the StaticArray class template
template <typename T, std::size_t N>
class StaticArray {
 private:
  // TODO: Add a private data member
  T data[N];

 public:
  // TODO: Add the size() method
  constexpr std::size_t size() const { return N; }
};

int main() {
  // TODO: Create a StaticArray and print its size
  StaticArray<double, 5> doubles_static_array;
  std::cout << "StaticArray size: " << doubles_static_array.size();

  return 0;
}