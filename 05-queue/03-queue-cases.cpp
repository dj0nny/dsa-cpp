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

  void enqueue(const T& value) {
    if (full()) {
      throw std::overflow_error{"Queue is full"};
    }

    std::size_t rear{(m_front + m_size) % Capacity};

    m_data[rear] = value;
    ++m_size;
  }

  T dequeue() {
    if (empty()) {
      throw std::underflow_error{"Queue is empty"};
    }

    T value{m_data[m_front]};
    m_front = (m_front + 1) % Capacity;
    --m_size;

    return value;
  }

  const T& front() const {
    if (empty()) {
      throw std::underflow_error{"Queue is empty"};
    }

    return m_data[m_front];
  }

  T& front() {
    if (empty()) {
      throw std::underflow_error{"Queue is empty"};
    }

    return m_data[m_front];
  }

  const T& back() const {
    if (empty()) {
      throw std::underflow_error{"Queue is empty"};
    }

    return m_data[(m_front + m_size - 1) % Capacity];
  }

  T& back() {
    if (empty()) {
      throw std::underflow_error{"Queue is empty"};
    }

    return m_data[(m_front + m_size - 1) % Capacity];
  }

  void clear() {
    m_size = 0;
    m_front = 0;
  }
};

struct Task {
  int id{};
  std::string name{};
};

int main() {
  Queue<int, 5> queue;

  std::cout << "Queue capacity: " << queue.capacity() << '\n';
  std::cout << "Queue size: " << queue.size() << '\n';
  std::cout << "Queue is empty: " << std::boolalpha << queue.empty() << std::noboolalpha << '\n';
  std::cout << "Enqueuing: 10 20 30" << '\n';
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  std::cout << "Front: " << queue.front() << ", Back: " << queue.back() << '\n';
  std::cout << "Size: " << queue.size() << '\n';
  std::cout << "Dequeued: " << queue.dequeue() << '\n';
  std::cout << "Dequeued: " << queue.dequeue() << '\n';
  std::cout << "Front after dequeues: " << queue.front() << '\n';
  std::cout << "Size: " << queue.size() << '\n';

  std::cout << "\n=== Task Scheduling ===\n";
  // TODO: Implement task scheduling with Queue<Task, 10>
  Queue<Task, 10> tasks{};

  // TODO: Fill queue to capacity and verify full()
  Task task_1{1, "Compile code"};
  tasks.enqueue(task_1);

  Task task_2{2, "Run tests"};
  tasks.enqueue(task_2);

  Task task_3{3, "Deploy app"};
  tasks.enqueue(task_3);

  Task current_task{tasks.dequeue()};
  std::cout << "Processing: Task " << current_task.id << " - " << current_task.name << '\n';

  current_task = tasks.dequeue();
  std::cout << "Processing: Task " << current_task.id << " - " << current_task.name << '\n';

  current_task = tasks.dequeue();
  std::cout << "Processing: Task " << current_task.id << " - " << current_task.name << '\n';
  std::cout << "All tasks completed!" << '\n';

  // TODO: Clear the queue and verify empty()
  std::cout << "\n=== Queue Operations ===\n";
  queue.clear();
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);

  std::cout << "After enqueue 1,2,3,4,5: size=" << queue.size() << ", full=" << (queue.full() ? "true" : "false") << '\n';
  queue.clear();
  std::cout << "After clear: size=" << queue.size() << ", empty=" << (queue.empty() ? "true" : "false") << '\n';

  std::cout << "\n=== Wraparound Demo ===\n";
  // TODO: Create Queue<int, 3> and demonstrate wraparound
  constexpr std::size_t size_2{3};
  Queue<int, size_2> short_queue{};

  // TODO: Enqueue values that wrap to beginning of array
  short_queue.enqueue(1);
  short_queue.enqueue(2);
  std::cout << "Dequeued: " << short_queue.dequeue() << '\n';
  std::cout << "Dequeued: " << short_queue.dequeue() << '\n';
  short_queue.enqueue(3);
  short_queue.enqueue(4);
  short_queue.enqueue(5);

  std::cout << "After wraparound - Front: " << short_queue.front() << ", Back: " << short_queue.back() << '\n';

  // TODO: Dequeue remaining elements to verify FIFO order
  std::cout << "Dequeued: " << short_queue.dequeue() << '\n';
  std::cout << "Dequeued: " << short_queue.dequeue() << '\n';
  std::cout << "Dequeued: " << short_queue.dequeue() << '\n';

  // TODO: Test error handling (underflow and overflow)
  std::cout << "\n=== Error Handling ===\n";
  try {
    short_queue.clear();
    short_queue.dequeue();
  } catch (const std::underflow_error& e) {
    std::cout << "Caught underflow: " << e.what() << '\n';
  }

  try {
    short_queue.enqueue(1);
    short_queue.enqueue(2);
    short_queue.enqueue(3);
    short_queue.enqueue(4);
    short_queue.enqueue(5);
  } catch (const std::overflow_error& e) {
    std::cout << "Caught overflow: " << e.what() << '\n';
  }

  return 0;
}
