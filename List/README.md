# List Data Structure

The `List` class is a C++ template class implementing a list data structure.

## Constructors
- `List()`: Creates an empty list.

- `List(int n)`: Creates a list with an initial capacity of `n`.

- `List(int n, const T& element)`: Creates a list with an initial capacity of `n`, and all elements set to `element`.

- `List(std::initializer_list<T> init_list)`: Creates a list and initializes it with a given initializer list.

## Methods
- `void clear()`: Removes all elements from the list.

- `void pop_back()`: Removes the last element from the list.

- `void pop_front()`: Removes the first element from the list.

- `void remove(int index)`: Removes the element at the specified index.

- `void push_back(const T& element)`: Adds an element to the end of the list.

- `void push_front(const T& element)`: Adds an element to the front of the list.

- `void insert(const T& element, int index)`: Inserts an element at the specified index.

- `void insert(const T& element, int start, int end)`: Inserts the element in a range defined by start and end indices. (end isn't included)

- `void resize(int new_size)`: Changes the size of the list.

- `void resize(int new_size, const T& element)`: Changes the size of the list and fills new elements with the specified value if the new size
  is greater than the previous one.

- `int size() const`: Returns the number of elements in the list.

- `int length() const`: An alias for `int size()`.

- `int capacity() const`: Returns the capacity of the list.

- `T& operator[](int index)`: Returns a reference to the element at the specified index.


## TODO
- Add comments to make the code more readable.

- add `void remove(int start, int end)` function.
