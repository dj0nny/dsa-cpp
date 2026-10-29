#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
 private:
  T* m_data;
  std::size_t m_size;
  std::size_t m_capacity;

  void resize(std::size_t new_capacity) {
    T* m_data_temp{new_capacity == 0 ? nullptr : new T[new_capacity]};

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

  void push_back(const T& value) {
    if (m_size == m_capacity) {
      std::size_t new_capacity{m_capacity == 0 ? 1 : m_capacity * 2};
      resize(new_capacity);
    }

    *(m_data + m_size) = value;
    ++m_size;
  }

  void pop_back() {
    if (m_size > 0) {
      --m_size;
    }
  }

  T& operator[](std::size_t index) { return m_data[index]; }

  const T& operator[](std::size_t index) const { return m_data[index]; }

  T& at(std::size_t index) {
    if (index >= m_size) throw std::out_of_range{"DynamicArray index out of range"};

    return m_data[index];
  }

  const T& at(std::size_t index) const {
    if (index >= m_size) throw std::out_of_range{"DynamicArray index out of range"};

    return m_data[index];
  }

  // TODO: Add clear() method
  void clear() { m_size = 0; }

  // TODO: Add empty() method
  bool empty() const { return m_size == 0; }

  // TODO: Add reserve() method
  void reserve(std::size_t requested_capacity) {
    if (requested_capacity > m_capacity) {
      resize(requested_capacity);
    }
  }

  // TODO: Add shrink_to_fit() method
  void shrink_to_fit() {
    if (m_size == 0) {
      resize(0);
    }

    if (m_capacity > m_size) {
      resize(m_size);
    }
  }
};

int main() {
  DynamicArray<int> d_array;

  d_array.push_back(10);
  d_array.push_back(20);
  d_array.push_back(30);
  d_array.push_back(40);
  d_array.push_back(50);

  std::cout << "After push_back: " << "Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  std::cout << "Elements:";
  for (std::size_t i{0}; i < d_array.size(); ++i) {
    std::cout << ' ' << d_array[i];
  }

  std::cout << '\n';

  constexpr std::size_t index = 2;
  std::cout << "Element at index " << index << ": " << d_array.at(index) << '\n';

  d_array.pop_back();
  std::cout << "After pop_back: " << "Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  // TODO: Call reserve(10) and print "After reserve(10): Size: 4, Capacity: 10"
  d_array.reserve(10);
  std::cout << "After reserve(10): Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  // TODO: Call clear() and print "After clear: Size: 0, Capacity: 10"
  d_array.clear();
  std::cout << "After clear: Size: " << d_array.size() << ", Capacity: " << d_array.capacity() << '\n';

  // TODO: Print "Is empty? true" using empty()
  std::cout << "Is empty? " << std::boolalpha << d_array.empty() << '\n';

  // TODO: Call shrink_to_fit() and print "After shrink_to_fit: Size: 0, Capacity: 0"
  d_array.shrink_to_fit();
  std::cout << "After shrink_to_fit: Size: " << d_array.size() << ", Capacity: " << d_array.capacity();

  return 0;
}
