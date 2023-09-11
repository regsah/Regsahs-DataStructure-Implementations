# LinkedList

LinkedList is a C++ template class implementing a singly linked list.

## TODO

- Adding comments and making the code more readable in general.
- Adding robust error handling.

## Constructors

- `LinkedList(int length)`: Creates a list of "length" nodes, initializing them with the default value.
- `LinkedList(int length, T startingData)`: Creates a list of "length" nodes, initializing them with "startingData."
- `LinkedList(std::initializer_list<T> list)`: Creates and initializes the object with an initializer list.

## Methods

- `void clear()`: Deletes all elements in the list.
- `void pop_front()`: Deletes the first node.
- `void pop_back()`: Deletes the last node.
- `void erase(int index)`: Deletes the node at a given index.
- `void erase(int begin, int end)`: Deletes all nodes with an index from "begin" to "end" (excluding "end").
- `void remove(int index)`: Deletes the node at a given index.
- `void remove(int begin, int end)`: Deletes all nodes with an index from "begin" to "end" (excluding "end").
- `void push_front(T newData)`: Adds a node to the front with the value of "newData."
- `void push_back(T newData)`: Adds a node to the back with the value of "newData."
- `void insert(int index, T newData)`: Adds a node to the given index with the value of "newData."
- `void resize(int newSize)`: Resizes the list (previous data carries over).
- `void reverse()`: Reverses the nodes.
- `T head()`, `T front()`, `T top()`: Returns the value at the head node.
- `T tail()`, `T back()`, `T bottom()`: Returns the value at the tail node.
- `int size()`: Returns the size of the list.
- `int length()`: Returns the size of the list.

## Operator Overloads

- `operator[]`: Overloaded to return the value of the node at a given index, similar to an array (0-based indexing). It should be noted that it has O(n) time complexity so while useful when accessing a spesific element, it shouldn't be used when traversing through elements.
- `operator()`: Works similarly to `operator[]` but returns the node itself (private).

## Usage

Since this is a template class, it can work with different types of homogeneous data. Declare it using the standard template class declaration (e.g., `LinkedList<int> myLinkedList(X);`).
