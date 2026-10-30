#include <cstddef>
#include <iostream>
#include <stdexcept>

struct Node {
  int data{};
  Node* next{};
};

class LinkedList {
 private:
  Node* m_head{};
  std::size_t m_size;

 public:
  LinkedList() : m_head{nullptr}, m_size{0} {}

  ~LinkedList() {
    while (m_head != nullptr) {
      Node* next{m_head->next};
      delete m_head;

      m_head = next;
    }

    m_size = 0;
  }

  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  bool is_empty() const { return m_head == nullptr; }

  std::size_t size() const { return m_size; }

  void push_front(int value) {
    Node* new_node{new Node{value}};

    new_node->next = m_head;
    m_head = new_node;

    ++m_size;
  }

  void push_back(int value) {
    Node* new_node{new Node{value}};

    if (is_empty()) {
      m_head = new_node;
    } else {
      Node* current{m_head};
      for (; current->next != nullptr; current = current->next);

      current->next = new_node;
    }
    ++m_size;
  }

  // TODO: Add front() const method
  // Returns the data of the first node, throws if empty
  int front() const {
    if (m_head == nullptr) {
      throw std::runtime_error{"front() called on empty list"};
    }

    return m_head->data;
  }

  // TODO: Add pop_front() method
  // Removes and deletes the first node
  void pop_front() {
    if (m_head == nullptr) {
      return;
    }

    Node* next_node{m_head->next};
    delete m_head;
    m_head = next_node;

    --m_size;
  }

  void print() const {
    for (Node* current{m_head}; current != nullptr; current = current->next) {
      std::cout << ' ' << current->data;
    }

    std::cout << '\n';
  }
};

int main() {
  LinkedList list{};

  list.push_back(10);
  list.push_back(20);
  list.push_back(30);

  std::cout << "List after push_back:";
  list.print();

  list.push_front(5);
  std::cout << "List after push_front(5):";
  list.print();

  std::cout << "Size: " << list.size() << '\n';

  // TODO: Add the following tests:
  // 1. Print "Front element: " followed by list.front()
  // 2. Call pop_front() and print "After pop_front: " followed by list.print()
  // 3. Call pop_front() again and print "After second pop_front: " followed by list.print()
  // 4. Print "Size after removals: " followed by list.size()
  std::cout << "Front element: " << list.front() << '\n';

  list.pop_front();
  std::cout << "After pop_front:";
  list.print();

  list.pop_front();
  std::cout << "After second pop_front:";
  list.print();

  std::cout << "Size after removals: " << list.size();

  return 0;
}
