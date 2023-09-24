# Heap Data Structure

The `Heap` class is a C++ template class implementing a heap data structure, supporting both max heap and min heap.

## Constructors
- `Heap()`: Creates an empty heap.

- `Heap(bool isMinHeap)`: Creates a heap, specifying whether it's a min heap (`true`) or a max heap (`false`).

## Methods
- `void clear()`: Removes all elements from the heap.

- `T top()`: Returns the top element (maximum for max heap, minimum for min heap) without removing it.

- `T pop()`: Removes and returns the top element (maximum for max heap, minimum for min heap).

- `void push(const T& element)`: Adds an element to the heap.

- `void heapifyUp()`: Moves the last added element to its correct position in the heap.

- `void heapifyDown()`: Restores the heap property starting from the root.

- `bool empty()`: Checks if the heap is empty.

## Private Helper Methods
- `int getLeftChildIndex(int index)`: Returns the index of the left child of a given index.

- `int getRightChildIndex(int index)`: Returns the index of the right child of a given index.

- `int getParentIndex(int index)`: Returns the index of the parent of a given index.

- `bool hasLeftChild(int index)`: Checks if a node has a left child.

- `bool hasRightChild(int index)`: Checks if a node has a right child.

- `bool hasParent(int index)`: Checks if a node has a parent.

- `void swap(int index1, int index2)`: Swaps the elements at two given indices.

## Usage
- Create a `Heap` object specifying whether it's a min heap or a max heap.

- Use `push` to add elements to the heap.

- Use `top` to access the top element without removing it.

- Use `pop` to remove and get the top element.

- Use `clear` to remove all elements from the heap.

- Use `empty` to check if the heap is empty.

