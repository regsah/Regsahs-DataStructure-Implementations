Stack Data Structure

The `Stack` class is a C++ template class implementing a stack data structure using a singly linked list.

## Constructors

- `Stack()`: Creates an empty stack.

- `Stack(std::initializer_list<T> list)`: Creates a stack and initializes it with elements from the provided initializer list. The first element in the list becomes the top of the stack.

## Methods

- `void clear()`: Removes all elements from the stack.

- `T pop()`: Removes and returns the top element from the stack. Throws an exception if the stack is empty.

- `void push(const T& data)`: Pushes a new element onto the top of the stack.

- `bool empty()`: Checks if the stack is empty.

- `T top()`: Returns the top element of the stack without removing it. Throws an exception if the stack is empty.

- `T peek()`: An alias for `top()`.

- `int size()`: Returns the number of elements in the stack.
