#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class List
{
private:
    int m_size{0};
    int m_capacity{0};

    T* m_data{};

public:
    List() = default;

    List(int n)
    {
        if (n < 0) throw std::invalid_argument("Initial capacity cannot be negative");

        m_capacity = n;
        m_size = n;

        m_data = new T[m_capacity];
    }

    List(int n, const T& element)
    {
        if (n < 0) throw std::invalid_argument("Initial capacity cannot be negative");

        m_capacity = n;
        m_size = n;

        m_data = new T[m_capacity];

        for(int i=0; i<m_size; ++i) m_data[i] = element;
    }

    List(std::initializer_list<T> init_list)
    {
        for (const T& element : init_list)
        {
            push_back(element);
        }
    }

    ~List()
    {
        clear();
    }

    void clear()
    {
        delete[] m_data;
        m_data = nullptr;

        m_capacity = 0;
        m_size = 0;
    }

    void pop_back()
    {
        if(m_size > 0)
        {
            --m_size;

            if(m_size < m_capacity/2)
            {
                m_capacity /= 2;
                
                T* new_data = new T[m_capacity];
                for(int i=0; i<m_size; ++i) new_data[i] = m_data[i];

                delete[] m_data;
                m_data = new_data;
            }
        }
        else 
        {
            throw std::runtime_error("Pop operation on an empty List");
        }
    }

    void pop_front()
    {
        if(m_size > 0)
        {
            --m_size;

            if(m_size < m_capacity/2)
            {
                m_capacity /= 2;
                
                T* new_data = new T[m_capacity];
                for(int i=0; i<m_size; ++i) new_data[i] = m_data[i+1];

                delete[] m_data;
                m_data = new_data;
            }
            else
            {
                for(int i=0; i<m_size; ++i) m_data[i] = m_data[i+1];
            }
        }
        else 
        {
            throw std::runtime_error("Pop operation on an empty List");
        }
    }

    void remove(int index)
    {
        if(index < 0) index += m_size;

        if(index == 0)
        {
            pop_front();
        }
        else if(index == m_size)
        {
            pop_back();
        }
        else if(index < m_size)
        {
            --m_size;

            if(m_size > m_capacity/2)
            {
                for(int i=index; i<m_size; ++i)
                {
                    m_data[i] = m_data[i+1]; 
                }
            }
            else
            {
                m_capacity = m_size;

                T* new_data = new T[m_capacity];
                for(int i=0; i<index; ++i) new_data[i] = m_data[i];
                for(int i=index; i<m_size; ++i) new_data[i] = m_data[i+1];

                delete[] m_data;
                m_data = new_data;
            }
        }
        else
        {
            throw std::runtime_error("Remove operation is out of bounds");
        }
    }

    void push_back(const T& element)
    {
        if(m_capacity == 0)
        {
            m_capacity = 1;
            m_data = new T[m_capacity];
        }
        else if(m_size == m_capacity)
        {
            m_capacity *= 2;

            T* new_data = new T[m_capacity];
            for(int i=0; i<m_size; ++i) new_data[i] = m_data[i];

            delete[] m_data;
            m_data = new_data; 
        }
        
        m_data[m_size] = element;
        ++m_size;
    }

    void push_front(const T& element)
    {
        if(m_capacity == 0)
        {
            m_capacity = 1;
            m_data = new T[m_capacity];
        }
        else if(m_size == m_capacity)
        {
            m_capacity *= 2;

            T* new_data = new T[m_capacity];
            for(int i=m_size; i>0; --i) new_data[i] = m_data[i-1];

            delete[] m_data;
            m_data = new_data;
        }
        else
        {
            for(int i=m_size; i>0; --i) m_data[i] = m_data[i-1];
        }

        m_data[0] = element;
        ++m_size;
    }

    void insert(const T& element, int index)
    {
        if(index == 0)
        {
            push_front(element);
        }
        else if(index == m_size)
        {
            push_back(element);
        }
        else if(index < m_size && index >= 0)
        {
            if(m_size == m_capacity)
            {
                m_capacity *= 2;

                T* new_data = new T[m_capacity];
                for(int i=0; i<index; ++i) new_data[i] = m_data[i];
                new_data[index] = element;
                for(int i=index; i<m_size; ++i) new_data[i+1] = m_data[i];

                delete[] m_data;
                m_data = new_data;
            }
            else
            {
                for(int i=m_size; i>index; --i) m_data[i] = m_data[i-1];
                m_data[index] = element;
            }
            ++m_size;
        }
        else
        {
            throw std::runtime_error("Insertion is out of bounds");
        }
    }

    void insert(const T& element, int start, int end)
    {
        for(int i=start; i<end; ++i)
        {
            insert(element, i);
        }
    }

    void resize(int new_size)
    {
        if(new_size < 0)
        {
            throw std::runtime_error("Size can't be negative");
        }
        else if(new_size == 0)
        {
            clear();
        }
        else if(new_size < m_size)
        {
            m_size = new_size;
            
            if(new_size < m_capacity/2)
            {
                m_capacity = new_size;
                
                T* new_data = new T[m_size];
                for(int i=0; i<m_size; ++i) new_data[i] = m_data[i];

                delete[] m_data;
                m_data = new_data;
            }
        }
        else if(new_size > m_size)
        {
            if(new_size <= m_capacity)
            {
                m_size = new_size;
            }
            else
            {
                m_capacity = new_size;

                T* new_data = new T[m_capacity];
                for(int i=0; i<m_size; ++i) new_data[i] = m_data[i];
                
                delete[] m_data;
                m_data = new_data;

                m_size = new_size;
            }
        }
    }

    void resize(int new_size, const T& element)
    {
        int old_size = m_size;
        resize(new_size);
        
        if(old_size < new_size)
        {
            for(int i=old_size; i<new_size; ++i)
            {
                m_data[i] = element;
            }
        }
    }

    int size() const
    {
        return m_size;
    }

    int length() const
    {
        return m_size;
    }

    int capacity() const
    {
        return m_capacity;
    }

    T& operator[](int index)
    {
        //turning negative indexes to positive relative to the end.
        if(index < 0) index += m_size;

        if(index >= m_size)
        {
            throw std::runtime_error("Index is out of bounds");
        }

        return m_data[index];
    }
};

#endif
