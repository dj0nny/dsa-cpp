#include <cstddef>
#include <iostream>

struct Node {
  int data{};
  Node* next{};
};

class LinkedList {
 private:
  Node* m_head{};
  // TODO: Add m_size member to track element count
  std::size_t m_size;

 public:
  LinkedList() : m_head{nullptr}, m_size{0} {}

  // TODO: Implement destructor to delete all nodes
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

  // TODO: Add size() method returning m_size
  std::size_t size() const { return m_size; }

  // TODO: Add push_front(int value) method
  // Creates new node at the beginning
  void push_front(int value) {
    Node* new_node{new Node{value}};

    new_node->next = m_head;
    m_head = new_node;

    ++m_size;
  }

  // TODO: Add push_back(int value) method
  // Creates new node at the end
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

  void print() const {
    for (Node* current{m_head}; current != nullptr; current = current->next) {
      std::cout << ' ' << current->data;
    }

    std::cout << '\n';
  }
};

int main() {
  LinkedList list{};

  // TODO: Replace the above output with the following tests:
  // 1. Use push_back to add 10, 20, 30
  // 2. Print "List after push_back: " followed by list.print()
  // 3. Use push_front to add 5
  // 4. Print "List after push_front(5): " followed by list.print()
  // 5. Print "Size: " followed by list.size()
  list.push_back(10);
  list.push_back(20);
  list.push_back(30);
  std::cout << "List after push_back:";
  list.print();
  list.push_front(5);
  std::cout << "List after push_front(5):";
  list.print();

  std::cout << "Size: " << list.size() << '\n';

  return 0;
}
