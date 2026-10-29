#include <cstddef>
#include <iostream>
#include <stdexcept>

// TODO: Create the DynamicArray class template
template <typename T>
class DynamicArray {
 private:
  // TODO: Add private data members
  T* m_data;
  std::size_t m_size;
  std::size_t m_capacity;

 public:
  // TODO: Add constructor
  DynamicArray() : m_data{nullptr}, m_size{0}, m_capacity{0} {}

  // TODO: Add destructor
  ~DynamicArray() { delete[] m_data; }

  // TODO: Add size() and capacity() methods
  std::size_t size() const { return m_size; }

  std::size_t capacity() const { return m_capacity; }
};

int main() {
  // TODO: Create a DynamicArray<int>
  DynamicArray<int> d_array;

  // TODO: Print "Size: 0, Capacity: 0"
  std::cout << "Size: " << d_array.size() << ", Capacity: " << d_array.capacity();

  return 0;
}
