#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list> 

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data{};
        Node* next{nullptr};

        Node() = default;
        Node(T val) :data{val}{}
    };

    int m_length{0};
    Node* m_top{nullptr};
    
public:
    Stack() = default;

    //first element of the list becomes the top element
    Stack(std::initializer_list<T> list)
    {
        for (auto it = list.end(); it != list.begin(); --it)
        {
            push(*(it - 1));
        }
    }

    ~Stack()
    {
        while(!empty())
        {
            pop();
        }
    }

    void clear()
    {
        while(!empty())
        {
            pop();
        }
    }

    T pop()
    {
        if(!empty())
        {
            T data = top();
            Node* old_top = m_top;
            m_top = m_top->next;
            delete old_top;
            --m_length;
            return data;
        }

        throw std::runtime_error("Pop operation on an empty stack");
    }

    void push(const T& data)
    {
        try
        {
            Node* element = new Node(data);
            element->next = m_top;
            m_top = element;
            ++m_length;
        }
        catch (const std::bad_alloc& e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        }
    }

    bool empty()
    {
        return m_top == nullptr;
    }

    T top()
    {
        if(m_top != nullptr) return m_top->data;
        throw std::runtime_error("Stack is empty");
    }

    T peek()
    {
        return top();
    }

    int size()
    {
        return m_length;
    }
};

#endif



