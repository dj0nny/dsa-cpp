#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

// TODO: Create the Stack class template
template <typename T>
class Stack {
 private:
  // TODO: Add private data members
  T* m_data{};
  std::size_t m_size{};
  std::size_t m_capacity{};

 public:
  // TODO: Add constructor
  Stack() : m_data{nullptr}, m_size{0}, m_capacity{0} {}

  // TODO: Add destructor
  ~Stack() {
    delete[] m_data;
    m_size = 0;
    m_capacity = 0;
  }

  // TODO: Delete copy constructor and copy assignment operator
  Stack(const Stack&) = delete;
  Stack& operator=(const Stack&) = delete;

  // TODO: Add size() method
  std::size_t size() const { return m_size; }

  // TODO: Add empty() method
  bool empty() const { return m_size == 0; }
};

int main() {
  // TODO: Create a Stack<int> named stack
  Stack<int> stack{};

  // TODO: Print the size and whether it's empty
  std::cout << "Stack size: " << stack.size() << '\n';
  std::cout << "Stack is empty: " << std::boolalpha << stack.empty() << std::noboolalpha << '\n';

  return 0;
}
