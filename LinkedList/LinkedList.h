#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list> 

template <typename T>
class LinkedList
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
    Node* m_head{nullptr};
    Node* m_tail{nullptr};

    Node* operator()(int index)
    {
        //turning negative indexes to positive relative to the end.
        if(index < 0) index += m_length;

        if (index == m_length-1) return m_tail;
        
        Node* current = m_head;
        while(index > 0 && current != nullptr)
        {
            current = current->next;
            --index;
        }

        return current;
    }
    
public:
    LinkedList() = default;

    LinkedList(int length)
        :m_length{length}
    {
        if(length == 0)
        {
            m_head == nullptr;
            m_tail == nullptr;
        }

        if(length > 0)
        {
            m_head = new Node();
            Node* current = m_head;
            
            for(int i = 1; i<length; ++i)
            {
                current->next = new Node();
                current = current->next;
            }

            m_tail = current;
        }
    }

    LinkedList(int length, T startingData)
        :m_length{length}
    {
        if(length > 0)
        {
            m_head = new Node(startingData);
            Node* current = m_head;
            
            for(int i = 1; i<length; ++i)
            {
                current->next = new Node(startingData);
                current = current->next;
                
            }

            m_tail = current;
        }
    }

    LinkedList(std::initializer_list<T> list) 
		: LinkedList(static_cast<T>(list.size()))
	{
        Node* current = nullptr;
        int m_length = 0;
		for (auto element : list)
		{
            if(m_length == 0)
            {
                m_head = new Node(element);
                current = m_head;
            }
            else
            {
                current->next = new Node(element);
                current = current->next;
            }
            ++m_length;
		}
        m_tail = current;
	}

    ~LinkedList()
    {
        Node* current = m_head;
        while (current != nullptr)
        {
            Node* temp  = current->next;
            delete current;
            current = temp;
        }
    }

    void clear()
    {
        //delete all nodes.
        Node* current = m_head;
        while(current != nullptr)
        {
            Node* temp = current->next;
            delete current;
            current = temp;
        }

        //update length and head.
        m_head = nullptr;
        m_tail = nullptr;
        m_length = 0;
    }

    void pop_front()
    {
        if(m_head == nullptr) return;

        Node* toDelete = m_head;
        m_head = m_head->next;
        delete toDelete;
        
        --m_length;
    }

    void pop_back()
    {
        if(m_head == nullptr) return;
        else if(m_head->next == nullptr)
        {
            clear();
            return;
        }

        Node* prevToLast = (*this)(m_length - 2);
        delete prevToLast->next;
        prevToLast->next = nullptr;
        
        m_tail = prevToLast;
        --m_length;
    }
    
    void erase(int index)
    {
        if(index < 0) index += m_length;

        if(index == 0)
        {
            pop_front();
            return;
        }
        else if(index == m_length-1)
        {
            pop_back();
            return;
        }
        
        Node* prevNode = (*this)(index-1);
        Node* nextNode = prevNode->next->next;
        delete prevNode->next;
        prevNode->next = nextNode;

        --m_length;
    }

    void erase(int begin, int end)
    {
        if(begin < 0) begin += m_length;
        if(end < 0) end += m_length;

        if(begin >= end || begin >= m_length) return;
        if(end > m_length) end = m_length;

        if(begin == 0 && end == m_length)
        {
            clear();
            return;
        }

        Node* prevNode = nullptr;
        Node* current = nullptr;

        if(begin == 0)
        {
            prevNode = nullptr;
            current = m_head;
            m_head = (*this)(end);
        }
        else
        {
            prevNode = (*this)(begin - 1);
            current = prevNode->next;
        }

        
        while(begin < end && current != nullptr)
        {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
            --m_length;
            ++begin;
        }

        if(prevNode != nullptr) prevNode->next = current;

        if(end = m_length && current == nullptr)
        {
            m_tail = prevNode;
        }
        
    }

    void remove(int index)
    {
        erase(index);
    }

    void remove(int begin, int end)
    {
        erase(begin, end);
    }

    void push_front(T newData)
    {
        if(m_length == 0)
        {
            m_head = new Node(newData);
            m_tail = m_head;
            ++m_length;
            return;
        }
        else if(m_length == 1)
        {
            Node* newHead = new Node(newData);
            newHead->next = m_head;
            m_head = newHead;
            ++m_length;
            return;
        }

        Node* newHead = new Node(newData);
        newHead->next = m_head;
        
        m_head = newHead;
        ++m_length;
    }

    void push_back(T newData)
    {
        if(m_length == 0)
        {
            m_head = new Node(newData);
            m_tail = m_head;
            ++m_length;
            return;
        }
        else if(m_length == 1)
        {
            m_tail = new Node(newData);
            m_head->next = m_tail;
            ++m_length;
            return;
        }

        m_tail->next = new Node(newData);
        m_tail = m_tail->next;
        ++m_length;
    }

    void insert(int index, T newData)
    {
        while(index < 0) index += m_length;

        if(index > m_length)
        {
            resize(index+1);
            (*this)[index] = newData;            
        }
        else if(index == m_length)
        {
            push_back(newData);
        }
        else if(index == 0)
        {
            push_front(newData);
        }
        else
        {
            Node* newNode = new Node(newData);
            Node* prev = (*this)(index-1);

            newNode->next = prev->next;
            prev->next = newNode;
            
            ++m_length;
        }
    }

    void resize(int newSize)
    {
        if(newSize == m_length) return;
        else if(newSize > m_length)
        {
            if(m_tail == nullptr)
            {
                m_tail = new Node();
                m_head = m_tail;
                ++m_length;
            }

            while(m_tail->next != nullptr)
            {
                m_tail = m_tail->next;
            }

            while(m_length < newSize)
            {
                m_tail->next = new Node();
                m_tail = m_tail->next;
                ++m_length;
            }
        }
        else
        {
            if(newSize == 0)
            {
                clear();
                return;
            }

            while(m_length > newSize)
            {
                pop_back();
            }
        }

        m_length = newSize;
    }

    void reverse()
    {
        if(m_head == nullptr || m_head->next == nullptr) return;

        m_tail = m_head;

        Node* prev = nullptr;
        Node* current = m_head;

        while(current != nullptr)
        {
            Node* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        m_head = prev;
    }
    
    T head()
    {
        return m_head->data;
    }

    T front()
    {
        return m_head->data;
    }

    T top()
    {
        return m_head->data;
    }

    T tail()
    {
        return m_tail->data;
    }

    T back()
    {
        return m_tail->data;
    }

    T bottom()
    {
        return m_tail->data;
    }

    int length()
    {
        return m_length;
    }

    int size()
    {
        return m_length;
    }

    T& operator[](int index)
    {
        //turning negative indexes to positive relative to the end.
        if(index < 0) index += m_length;

        Node* current = m_head;
        while(index > 0)
        {
            current = current->next;
            --index;
        }

        return current->data;
    }
};



#endif



