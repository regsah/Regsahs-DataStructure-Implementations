#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

template <typename T>
class BSTree
{
private:
    struct Node
    {
        T data{};
        Node* left{nullptr};
        Node* right{nullptr};

        Node() = default;
        Node(T val) :data{val}{}
    };

    Node* m_root{nullptr};
    
    Node* insertRecursive(Node* node, const T& value)
    {
        if(node == nullptr) return new Node(value);

        if(value < node->data) node->left = insertRecursive(node->left, value);
        else if(value > node->data) node->right = insertRecursive(node->right, value);      

        return node;
    }

    bool searchRecursive(Node* node, const T& value)
    {
        if(node == nullptr) return false;

        if(node->data == value) return true;
        else if(node->data < value) return searchRecursive(node->right, value);
        else return searchRecursive(node->left, value);
    }

    Node* removeRecursive(Node* node, const T& value)
    {
        if(node == nullptr) return nullptr;

        if(node->data > value) node->left = removeRecursive(node->left, value);
        else if(node->data < value) node->right = removeRecursive(node->right, value);
        else
        {
            if(node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }
        return node;
    }

    Node* findMin(Node* node)
    {
        while(node->left != nullptr) node = node->left;
        return node;
    }

    void clearRecursive(Node* node)
    {
        if(node == nullptr) return;

        clearRecursive(node->left);
        clearRecursive(node->right);
        delete node;
    }


public:
    BSTree() = default;
    
    ~BSTree()
    {
        clear();
    }
    
    void clear()
    {
        if(m_root != nullptr)
        {
            clearRecursive(m_root);
            m_root = nullptr;
        }
    }

    void insert(const T& value)
    {
        m_root = insertRecursive(m_root, value);
    }

    bool search(const T& value)
    {
        return searchRecursive(m_root, value);
    }

    void remove(const T& value) 
    {
        m_root = removeRecursive(m_root, value);
    }

    bool empty()
    {
        return m_root == nullptr;
    }
};


#endif
