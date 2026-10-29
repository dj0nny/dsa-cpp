#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
 private:
  T* m_data;
  std::size_t m_size;
  std::size_t m_capacity;

  // TODO: Add private resize() method
  void resize(std::size_t new_capacity) {
    T* m_data_temp{new T[new_capacity]};

    for (std::size_t i{0}; i < m_size; ++i) {
      *(m_data_temp + i) = *(m_data + i);
    }

    delete[] m_data;

    m_data = m_data_temp;
    m_capacity = new_capacity;
  }

 public:
  DynamicArray() : m_data{nullptr}, m_size{0}, m_capacity{0} {}

  ~DynamicArray() { delete[] m_data; }

  std::size_t size() const { return m_size; }

  std::size_t capacity() const { return m_capacity; }

  // TODO: Add push_back() method
  void push_back(const T& value) {
    if (m_size == m_capacity) {
      std::size_t new_capacity{m_capacity == 0 ? 1 : m_capacity * 2};
      resize(new_capacity);
    }

    *(m_data + m_size) = value;
    ++m_size;
  }

  // TODO: Add pop_back() method
  void pop_back() {
    if (m_size > 0) {
      --m_size;
    }
  }

  // TODO: Add operator[] (non-const version)
  T& operator[](std::size_t index) { return m_data[index]; }

  // TODO: Add operator[] (const version)
  const T& operator[](std::size_t index) const { return m_data[index]; }

  // TODO: Add at() (non-const version)
  T& at(std::size_t index) {
    if (index >= m_size) throw std::out_of_range{"DynamicArray index out of range"};

    return m_data[index];
  }

  // TODO: Add at() (const version)
  const T& at(std::size_t index) const {
    if (index >= m_size) throw std::out_of_range{"DynamicArray index out of range"};

    return m_data[index];
  }
};

int main() {
  DynamicArray<int> d_array;

  std::cout << "Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  // TODO: Add elements 10, 20, 30, 40, 50 using push_back()
  d_array.push_back(10);
  d_array.push_back(20);
  d_array.push_back(30);
  d_array.push_back(40);
  d_array.push_back(50);

  // TODO: Print "After push_back: Size: 5, Capacity: 8"
  std::cout << "After push_back: " << "Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  // TODO: Print "Elements: 10 20 30 40 50"
  std::cout << "Elements:";
  for (std::size_t i{0}; i < d_array.size(); ++i) {
    std::cout << ' ' << d_array[i];
  }

  std::cout << '\n';

  // TODO: Print "Element at index 2: 30" using at()
  constexpr std::size_t index = 2;
  std::cout << "Element at index " << index << ": " << d_array.at(index) << '\n';

  // TODO: Call pop_back() and print "After pop_back: Size: 4, Capacity: 8"
  d_array.pop_back();
  std::cout << "After pop_back: " << "Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  return 0;
}
