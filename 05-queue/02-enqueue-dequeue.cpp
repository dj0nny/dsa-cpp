#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, std::size_t Capacity>
class Queue {
 private:
  T m_data[Capacity]{};
  std::size_t m_front{};
  std::size_t m_size{};

 public:
  Queue() : m_front{0}, m_size{0} {};

  std::size_t size() const { return m_size; }

  bool empty() const { return m_size == 0; }

  std::size_t full() const { return m_size == Capacity; }

  constexpr std::size_t capacity() const { return Capacity; }

  // TODO: Add enqueue() method
  void enqueue(const T& value) {
    if (full()) {
      throw std::overflow_error{"The queue is full"};
    }

    std::size_t rear{(m_front + m_size) % Capacity};

    m_data[rear] = value;
    ++m_size;
  }

  // TODO: Add dequeue() method
  T dequeue() {
    if (empty()) {
      throw std::underflow_error{"The queue is empty"};
    }

    T value{m_data[m_front]};
    m_front = (m_front + 1) % Capacity;
    --m_size;

    return value;
  }

  // TODO: Add front() methods (const and non-const)
  const T& front() const {
    if (empty()) {
      throw std::underflow_error{"The queue is empty"};
    }

    return m_data[m_front];
  }

  T& front() {
    if (empty()) {
      throw std::underflow_error{"The queue is empty"};
    }

    return m_data[m_front];
  }

  // TODO: Add back() methods (const and non-const)
  const T& back() const {
    if (empty()) {
      throw std::underflow_error{"The queue is empty"};
    }

    return m_data[(m_front + m_size - 1) % Capacity];
  }

  T& back() {
    if (empty()) {
      throw std::underflow_error{"The queue is empty"};
    }

    return m_data[(m_front + m_size - 1) % Capacity];
  }

  // TODO: Add clear() method
  void clear() {
    m_size = 0;
    m_front = 0;
  }
};

int main() {
  constexpr std::size_t size{5};
  Queue<int, size> queue;

  std::cout << "Queue capacity: " << queue.capacity() << '\n';
  std::cout << "Queue size: " << queue.size() << '\n';
  std::cout << "Queue is empty: " << std::boolalpha << queue.empty() << std::noboolalpha;
  std::cout << "Enqueuing: 10 20 30" << '\n';
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  std::cout << "Front: " << queue.front() << ", Back: " << queue.back() << '\n';
  std::cout << "Size: " << queue.size() << '\n';
  std::cout << "Dequeued: " << queue.dequeue() << '\n';
  std::cout << "Dequeued: " << queue.dequeue() << '\n';
  std::cout << "Front after dequeues: " << queue.front() << '\n';
  std::cout << "Size: " << queue.size();

  return 0;
}
