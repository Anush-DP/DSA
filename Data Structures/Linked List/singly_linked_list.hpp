#include "../Utils/node.hpp"

#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

template<typename T>
class singly_linked_list
{
private:
    node<T> *head;
    int list_size;
public:
    singly_linked_list(): head(nullptr), list_size(0){}
    ~singly_linked_list();
    void insert(T);
    void erase(T);
    int size() const;
    void reverse();
    void print();
};

template<typename T>
void singly_linked_list<T>::insert(T data)
{
    list_size++;
    if(head == nullptr)
    {
        head = new node<T>;
        head->data = data;
        head->next = nullptr;
        return;
    }
    auto curr = head;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }
    decltype(head) temp = new node<T>;
    temp->next = nullptr;
    temp->data = data;
    curr->next = temp;
}

template<typename T>
singly_linked_list<T>::~singly_linked_list()
{
    if(head == nullptr) return;
    auto next = head->next;
    while(next != nullptr)
    {
        delete head;
        head = next;
        next = head->next;
    }
    delete head;
}

template<typename T>
void singly_linked_list<T>::erase(T data)
{
    if(head == nullptr) return;
    auto curr = head;
    decltype(head) prev = nullptr;
    if(curr->data == data)
    {
        head = curr->next;
        delete curr;
        list_size--;
        return;
    }
    prev = curr;
    curr = curr->next;
    while(curr != nullptr)
    {
        if(curr->data == data)
        {
            prev->next = curr->next;
            delete curr;
            list_size--;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

template<typename T>
int singly_linked_list<T>::size() const
{
    return list_size;
}

template<typename T>
void singly_linked_list<T>::reverse()
{
    auto curr = head;
    decltype(head) prev = nullptr, next = nullptr;
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template<typename T>
void singly_linked_list<T>::print()
{
    auto curr = head;
    while(curr != nullptr)
    {
        std::cout << curr->data << "->";
        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;
}

#endif