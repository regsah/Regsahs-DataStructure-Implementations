#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdexcept>

#include "List.h"

template <typename T>
class Heap
{
private:
    List<T> heap;
    bool isMinHeap = false;
    
    int getLeftChildIndex(int index) { return index*2 + 1; }
    int getRightChildIndex(int index) { return index*2 + 2; }
    int getParentIndex(int index) { return (index-1)/2; }

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < heap.size(); }
    bool hasRightChild(int index) { return getRightChildIndex(index) < heap.size(); }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index)   { return heap[getLeftChildIndex(index)]; }
    int rightChild(int index) { return heap[getRightChildIndex(index)]; }
    int parent(int index) { return heap[getParentIndex(index)]; }

    void swap(int index1, int index2)
    {
        T temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    Heap() = default;

    Heap(bool isMinHeap):isMinHeap{isMinHeap}{}

    ~Heap()
    {
        clear();
    }

    void clear()
    {
        heap.clear();
    }

    T top() 
    {
        if(heap.size() == 0) throw std::invalid_argument("Heap is empty.");

        return heap[0];
    }

    T pop()
    {
        if(heap.size() == 0) throw std::invalid_argument("Heap is empty.");

        T element = heap[0];
        swap(0, heap.size()-1);
        heap.pop_back();
        heapifyDown();

        return element;
    }

    void push(T element)
    {
        heap.push_back(element);
        heapifyUp();
    }

    void heapifyUp()
    {
        int index = heap.size() - 1;

        while (hasParent(index) && 
               ((isMinHeap && parent(index) > heap[index]) || (!isMinHeap && parent(index) < heap[index])))
        {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

    void heapifyDown()
    {
        int index = 0;

        while (hasLeftChild(index))
        {
            int childIndex = getLeftChildIndex(index);
            if (hasRightChild(index) &&
                ((isMinHeap && rightChild(index) < leftChild(index)) || (!isMinHeap && rightChild(index) > leftChild(index))))
            {
                childIndex = getRightChildIndex(index);
            }

            if ((isMinHeap && heap[index] <= heap[childIndex]) || (!isMinHeap && heap[index] >= heap[childIndex]))
            {
                break;
            }
            swap(index, childIndex);
            index = childIndex;
        }
    }

    bool empty()
    {
        return heap.size() == 0;
    }
};

#endif
