# LinkedList
a linked list implementation in C++

TODO:
- Adding comments and making the code more readable in general
- Adding robust error handling 
- Adding a proper print() method and overloading the << operator.

Constructors:
- LinkedList(int length): Creates a list of "length" nodes, initializes the nodes with the default value.
- LinkedList(int length, T startingData): creates a list of "length" nodes, initializes the nodes with the startingNode.
- LinkedList(std::initializer_list\<T\> list): creates and initializes the object with an initializer_list ("{}"). 

Methods:
- void clear(): deletes everything in the object.
- void pop_front(): deletes the first node.
- void pop_back(): deletes the last node.
- void erase(int index): deletes the node at a given index.
- void erase(int begin, int end): deletes all nodes with an index from "begin" to "end" ("end" isn't included)
- void remove(int index): deletes the node at a given index.
- void remove(int begin, int end): deletes all nodes with an index from "begin" to "end" ("end" isn't included)
- void push_front(T newData): adds a node to the front with the value of newData.
- void push_back(T newData): adds a node to the back with the value of newData.
- void insert(int index, T newData): adds a node to the given index with the value of newData.
- void resize(int newSize): resizes the object (previous data carries over).
- void reverse(): reverses the nodes.
- T head(): returns the value at the head node.
- T front(): returns the value at the head node.
- T top(): returns the value at the head node.
- T tail(): returns the value at the tail node.
- T back(): returns the value at the tail node.
- T bottom(): returns the value at the tail node.
- int size(): returns the size of the list.
- int length(): returns the size of the list.


Operator overloads:

1) "[]" :
- Overloaded it so that it returns the value of the node at a given index like an array.
- The first node is at the 0th index like an array.
- Has O(n) time complexity so while it is useful when accessing a spesific node, it shouldn't be used when traversing through all elements of the list.

2) "()"
- Works similar to the "[]" operator.
- it returns the node itself.
- it is private.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Note: Since it is a template class, it can take different types of homogenous data and it should be declared with the standard template class declaration 
(ex: LinkedList\<int\> myLinkedList(X);)
  

