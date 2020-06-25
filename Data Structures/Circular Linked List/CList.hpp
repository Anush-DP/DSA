#include "../Utils/node.hpp"

#ifndef CLIST_HPP
#define CLIST_HPP

template<typename T>
class CircularSinglyLinkedList
{
    Node<T> *tail = nullptr;

    public:
        CircularSinglyLinkedList(): tail(nullptr){}
        ~CircularSinglyLinkedList();
        void push_back(T);
        void push_front(T);
        void erase(T);
        int size();
        void print();
};

template<typename T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList()
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
void CircularSinglyLinkedList<T>::push_back(T data)
{
    if(tail == nullptr)
    {
        tail = new Node<T>;
        tail->data = data;
        tail->next = tail;
        return;
    }
    auto head = tail->next;
    tail->next = new Node<T>;
    tail = tail->next;
    tail->data = data;
    tail->next = head;
}

template<typename T>
void CircularSinglyLinkedList<T>::push_front(T data)
{
    if(tail == nullptr)
    {
        tail = new Node<T>;
        tail->data = data;
        tail->next = tail;
        return;
    }
    auto head = tail->next;
    tail->next = new Node<T>;
    tail->next->data = data;
    tail->next->next = head;
}

template<typename T>
void CircularSinglyLinkedList<T>::erase(T data)
{
    if(tail == nullptr) return;
    auto head = tail->next;
    if(head->data == data)
    {
        if(head->next == head)
        {
            delete tail;
            tail = nullptr;
            return;
        }
        tail->next = head->next;
        delete head;
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
            return;
        }
        prev = head;
    }
}

template<typename T>
int CircularSinglyLinkedList<T>::size()
{
    int size = 0;
    if(tail == nullptr) return size;
    auto head = tail;
    do
    {
        size++;
        head = head->next;
    } while (head != tail);
    return size;
}

template<typename T>
void CircularSinglyLinkedList<T>::print()
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