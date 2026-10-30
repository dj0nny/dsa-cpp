#include <iostream>

// TODO: Create the Node struct
struct Node {
  int data{};
  Node* next{};
};

// TODO: Create the LinkedList class
class LinkedList {
 private:
  // TODO: Add private m_head pointer
  Node* m_head{};

 public:
  // TODO: Add constructor
  LinkedList() : m_head{nullptr} {}

  // TODO: Add destructor
  ~LinkedList() {}

  // TODO: Delete copy constructor and assignment operator (Rule of Three)
  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  // TODO: Add is_empty() method
  bool is_empty() const { return m_head == nullptr; }

  // TODO: Add print() method
  void print() const {}
};

int main() {
  // TODO: Create a LinkedList named list
  LinkedList list{};

  // TODO: Print "LinkedList created successfully!"
  std::cout << "LinkedList created successfully!" << '\n';

  // TODO: Print "List is empty: yes"
  std::cout << "List is empty: " << (list.is_empty() ? "yes" : "no");

  return 0;
}
