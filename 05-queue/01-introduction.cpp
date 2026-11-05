#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

// TODO: Create the Queue class template
template <typename T, std::size_t Capacity>
class Queue {
  // TODO: Add private data members
 private:
  T m_data[Capacity]{};
  std::size_t m_front{};
  std::size_t m_size{};

 public:
  // TODO: Add constructor
  Queue() : m_front{0}, m_size{0} {}

  // TODO: Add size() method
  std::size_t size() const { return m_size; }

  // TODO: Add empty() method
  bool empty() const { return m_size == 0; }

  // TODO: Add full() method
  std::size_t full() const { return m_size == Capacity; }

  // TODO: Add capacity() method
  constexpr std::size_t capacity() const { return Capacity; }
};

int main() {
  // TODO: Create a Queue<int, 5>
  constexpr std::size_t size{5};
  Queue<int, size> queue;

  // TODO: Print the capacity
  std::cout << "Queue capacity: " << queue.capacity() << '\n';

  // TODO: Print the size
  std::cout << "Queue size: " << queue.size() << '\n';

  // TODO: Print whether queue is empty
  std::cout << "Queue is empty: " << std::boolalpha << queue.empty() << std::noboolalpha;

  return 0;
}
