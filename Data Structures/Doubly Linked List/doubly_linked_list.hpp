#include "../Utils/tree_node.hpp"

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

template<typename T>
class doubly_linked_list
{
private:
    tree_node<T> *head = nullptr;
public:
    doubly_linked_list(): head(nullptr){}
    ~doubly_linked_list();
    void push_back(T data);
    void push_front(T data);
    void erase(T data);
    int size();
    void print();
};

template<typename T>
doubly_linked_list<T>::~doubly_linked_list()
{

}

#endif