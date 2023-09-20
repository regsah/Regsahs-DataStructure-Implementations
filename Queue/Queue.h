#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list> 
#include <stdexcept>

template <typename T>
class Queue
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
    Node* m_front{nullptr};
    Node* m_back{nullptr};
    
public:
    Queue() = default;

    Queue(std::initializer_list<T> list)
    {
        for (const T& element : list)
        {
            enqueue(element);
        }
    }

    ~Queue()
    {
        clear();
    }

    void clear()
    {
        while(m_front != nullptr)
        {
            dequeue();
        }
    }

    T dequeue()
    {
        if(!isEmpty())
        {   
            Node* old_front = m_front;
            T data = old_front->data;

            if(m_front == m_back) m_back = nullptr;

            m_front = m_front->next;
            delete old_front;
            
            --m_length;
            return data;
        }

        throw std::runtime_error("Dequeue operation on an empty queue");
    }

    void enqueue(const T& data)
    {
        try
        {
            Node* element = new Node(data);
            if(m_back == nullptr)
            {
                m_front = element;
                m_back = element;
            }
            else
            {
                m_back->next = element;
                m_back = element;
            }
            ++m_length;
        }
        catch(const std::bad_alloc& e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << "\n";     
        } 
    }

    bool isEmpty()
    {
        return m_front == nullptr;
    }

    T front()
    {
        return m_front->data;
    }

    int size()
    {
        return m_length;
    }

    int length()
    {
        return m_length;
    }

    Queue& operator=(const Queue& other) {
        if (this == &other) return *this;

        clear();

        Node* current = other.m_front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }

        return *this;
    }
};

#endif
