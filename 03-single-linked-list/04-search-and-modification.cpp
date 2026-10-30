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

  int front() const {
    if (m_head == nullptr) {
      throw std::runtime_error{"front() called on empty list"};
    }

    return m_head->data;
  }

  void pop_front() {
    if (m_head == nullptr) {
      return;
    }

    Node* next_node{m_head->next};
    delete m_head;
    m_head = next_node;

    --m_size;
  }

  // TODO: Add find(int value) method
  // Returns pointer to node containing value, or nullptr if not found
  Node* find(int value) const {
    for (Node* current{m_head}; current != nullptr; current = current->next) {
      if (current->data == value) {
        return current;
      }
    }

    return nullptr;
  }

  // TODO: Add insert_after(Node* node, int value) method
  // Inserts new node with value after the given node
  void insert_after(Node* node, int value) {
    if (node == nullptr) {
      return;
    }

    Node* next_node{node->next};
    Node* new_node{new Node{value}};

    new_node->next = next_node;
    node->next = new_node;

    ++m_size;
  }

  // TODO: Add remove(int value) method
  // Removes first occurrence of value, returns true if found
  bool remove(int value) {
    if (m_head == nullptr) {
      return false;
    }

    if (m_head->data == value) {
      Node* next{m_head->next};
      delete m_head;
      m_head = next;

      --m_size;

      return true;
    }

    Node* prev{m_head};

    for (Node* current{m_head->next}; current != nullptr; current = current->next) {
      if (current->data == value) {
        prev->next = current->next;

        delete current;

        --m_size;

        return true;
      }

      prev = current;
    }

    return false;
  }

  // TODO: Add clear() method
  // Removes all nodes from the list
  void clear() {
    while (m_head != nullptr) {
      Node* next{m_head->next};
      delete m_head;

      m_head = next;
    }

    m_size = 0;
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

  std::cout << "Front element: " << list.front() << '\n';

  list.pop_front();
  std::cout << "After pop_front:";
  list.print();

  list.pop_front();
  std::cout << "After second pop_front:";
  list.print();

  std::cout << "Size after removals: " << list.size() << '\n';

  // TODO: Test find() for 30 (should find) and 99 (should not find)
  std::cout << "Finding 30: " << (list.find(30) != nullptr ? "found" : "not found") << '\n';
  std::cout << "Finding 99: " << (list.find(99) != nullptr ? "found" : "not found") << '\n';

  // TODO: Test insert_after() - insert 35 after 30
  list.insert_after(list.find(30), 35);
  std::cout << "After insert_after 30, 35:";
  list.print();

  // TODO: Test remove() - remove 20
  list.remove(20);
  std::cout << "After remove 20:";
  list.print();

  // TODO: Test remove() on head element
  list.remove(list.front());
  std::cout << "After remove 30 (head):";
  list.print();

  // TODO: Test clear()
  list.clear();
  std::cout << "After clear: " << (list.is_empty() ? "(empty)" : "not empty") << ", size: " << list.size() << '\n';

  // TODO: Test edge cases - remove from empty list, single element operations
  std::cout << "Remove from empty: " << (list.remove(42) ? "found" : "not found") << '\n';
  list.push_front(42);
  std::cout << "Single element list:";
  list.print();
  list.remove(list.front());
  std::cout << "After removing only element: " << (list.is_empty() ? "(empty)" : "not empty");

  return 0;
}
