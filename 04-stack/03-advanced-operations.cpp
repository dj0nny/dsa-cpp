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

  void pop() {
    if (empty()) {
      throw std::underflow_error{"Stack underflow"};
    }

    --m_size;
  }

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

  // TODO: Add clear() method
  void clear() { m_size = 0; }

  // TODO: Add swap() method
  void swap(Stack& other) {
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
  }
};

// TODO: Add is_balanced() function
bool is_balanced(const std::string& str) {
  Stack<char> brackets{};

  for (char ch : str) {
    if (ch == '(' || ch == '[' || ch == '{') {
      brackets.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (brackets.empty()) {
        return false;
      }
      char top{brackets.top()};
      brackets.pop();
      if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
        return false;
      }
    }
  }

  return brackets.empty();
}

int main() {
  Stack<int> stack{};

  stack.push(1);
  stack.push(2);
  stack.push(3);

  // TODO: Test clear()
  std::cout << "Testing clear():" << '\n';
  std::cout << "Size before clear: " << stack.size() << '\n';
  stack.clear();
  std::cout << "Size after clear: " << stack.size() << '\n';

  // TODO: Test swap()
  Stack<char> char_stack_1{};

  char_stack_1.push('A');
  char_stack_1.push('B');

  Stack<char> char_stack_2{};

  char_stack_2.push('1');
  char_stack_2.push('2');

  std::cout << "Testing swap():" << '\n';
  char_stack_1.swap(char_stack_2);
  std::cout << "After swap - stack1 top: " << char_stack_1.top() << ", stack2 top: " << char_stack_2.top() << '\n';

  // TODO: Test is_balanced()
  std::cout << "Testing balanced parentheses:" << '\n';
  std::cout << "\"\" is balanced: " << (is_balanced("") ? "true" : "false") << '\n';
  std::cout << "\"()\" is balanced: " << (is_balanced("()") ? "true" : "false") << '\n';
  std::cout << "\"([{}])\" is balanced: " << (is_balanced("([{}])") ? "true" : "false") << '\n';
  std::cout << "\"(]\" is balanced: " << (is_balanced("(]") ? "true" : "false") << '\n';
  std::cout << "\"(()\" is balanced: " << (is_balanced("(()") ? "true" : "false") << '\n';
  std::cout << "\")\" is balanced: " << (is_balanced(")") ? "true" : "false") << '\n';

  return 0;
}
