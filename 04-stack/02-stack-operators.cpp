#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

template <typename T>
class Stack {
 private:
  T* m_data{};
  std::size_t m_size{};
  std::size_t m_capacity{};

 public:
  Stack() : m_data{nullptr}, m_size{0}, m_capacity{0} {}

  ~Stack() {
    delete[] m_data;
    m_size = 0;
    m_capacity = 0;
  }

  Stack(const Stack&) = delete;
  Stack& operator=(const Stack&) = delete;

  std::size_t size() const { return m_size; }

  bool empty() const { return m_size == 0; }

  // TODO: Add push() method
  void push(const T& value) {
    if (m_size == m_capacity) {
      std::size_t new_capacity{m_capacity == 0 ? 1 : m_capacity * 2};

      T* new_stack_data{new T[new_capacity]{}};

      for (std::size_t idx{0}; idx < m_capacity; ++idx) {
        new_stack_data[idx] = m_data[idx];
      }

      delete[] m_data;

      m_data = new_stack_data;
      m_capacity = new_capacity;
    }

    m_data[m_size] = value;
    ++m_size;
  }

  // TODO: Add pop() method
  void pop() {
    if (empty()) {
      throw std::underflow_error{"Stack underflow"};
    }

    --m_size;
  }

  // TODO: Add top() methods (const and non-const)
  T& top() {
    if (empty()) {
      throw std::underflow_error{"Stack underflow"};
    }

    return m_data[m_size - 1];
  }

  const T& top() const {
    if (empty()) {
      throw std::underflow_error{"Stack underflow"};
    }

    return m_data[m_size - 1];
  }
};

int main() {
  Stack<int> stack{};

  // TODO: Push 10, 20, 30 onto the stack
  stack.push(10);
  stack.push(20);
  stack.push(30);

  // TODO: Print "After pushing 10, 20, 30:"
  std::cout << "After pushing 10, 20, 30:" << '\n';

  // TODO: Print the top element using top()
  std::cout << "Top element: " << stack.top() << '\n';

  // TODO: Print the stack size
  std::cout << "Stack size: " << stack.size() << "\n";

  // TODO: Pop one element
  stack.pop();

  // TODO: Print a blank line, then "After popping 30:"
  std::cout << "\nAfter popping 30:" << '\n';

  // TODO: Print the top element and size again
  std::cout << "Top element: " << stack.top() << '\n';
  std::cout << "Stack size: " << stack.size();

  return 0;
}
