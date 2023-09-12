# Queue Data Structure

The `Queue` class is a C++ template class implementing a queue data structure using a singly linked list.

## Constructors
- `Queue()`: Creates an empty queue.

- `Queue(std::initializer_list<T> list)`: Creates a queue and initializes it with a given initializer list. The first element in the list becomes the front of the queue.

## Methods
- `void clear()`: Removes all elements from the queue.

- `T dequeue()`: Removes and returns the front element from the queue. Throws an exception if the queue is empty.

- `void enqueue(const T& data)`: Pushes a new element onto the back of the queue.

- `bool isEmpty()`: Checks if the queue is empty.

- `T front()`: Returns the front element of the queue without removing it. Throws an exception if the queue is empty.

- `int size()`: Returns the number of elements in the queue.
  
- `int length()`: An alias for the `int size()`
