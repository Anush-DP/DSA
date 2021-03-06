#include "../Utils/node.hpp"

#ifndef CLIST_HPP
#define CLIST_HPP

template<typename T>
class circular_linked_list
{
private:
    node<T> *tail;
    int list_size;
public:
    circular_linked_list(): tail(nullptr), list_size(0){}
    ~circular_linked_list();
    void push_back(T);
    void push_front(T);
    void erase(T);
    int size() const;
    void print();
};

template<typename T>
circular_linked_list<T>::~circular_linked_list()
{
    if(tail == nullptr) return;
    auto head = tail->next;
    decltype(tail) prev = nullptr;
    while(head != tail)
    {
        prev = head->next;
        delete head;
        head = prev;
    }
    delete tail;
}

template<typename T>
void circular_linked_list<T>::push_back(T data)
{
    list_size++;
    if(tail == nullptr)
    {
        tail = new node<T>;
        tail->data = data;
        tail->next = tail;
        return;
    }
    auto head = tail->next;
    tail->next = new node<T>;
    tail = tail->next;
    tail->data = data;
    tail->next = head;
}

template<typename T>
void circular_linked_list<T>::push_front(T data)
{
    list_size++;
    if(tail == nullptr)
    {
        tail = new node<T>;
        tail->data = data;
        tail->next = tail;
        return;
    }
    auto head = tail->next;
    tail->next = new node<T>;
    tail->next->data = data;
    tail->next->next = head;
}

template<typename T>
void circular_linked_list<T>::erase(T data)
{
    if(tail == nullptr) return;
    auto head = tail->next;
    if(head->data == data)
    {
        if(head->next == head)
        {
            delete tail;
            tail = nullptr;
            list_size--;
            return;
        }
        tail->next = head->next;
        delete head;
        list_size--;
        return;
    }
    auto prev = head;
    while(head != tail)
    {
        head = head->next;
        if(head->data == data)
        {
            prev->next = head->next;
            delete head;
            list_size--;
            return;
        }
        prev = head;
    }
}

template<typename T>
int circular_linked_list<T>::size() const
{
    return list_size;
}

template<typename T>
void circular_linked_list<T>::print()
{
    auto curr = tail;
    do
    {
        if(curr == nullptr) break;
        curr = curr->next;
        std::cout << curr->data << "->";
    } while (curr != tail);
    std::cout << "Head\n";
}

#endif