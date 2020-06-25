#include <iostream>
#include "./Linked List/List.hpp"
#include "Circular Linked List/CList.hpp"
using namespace std;

template<typename T>
bool list_IO(List<T>&);
template<typename T>
bool circularSinglyLinkedList_IO(CircularSinglyLinkedList<T>&);

int main()
{
    List<string> list;
    CircularSinglyLinkedList<string> cll;
    int x;
    cout << "1. Singly linked list\n";
    cout << "2. Circular singly linked list\n";
    cin >> x;
    switch (x)
    {
    case 1:
        while(list_IO(list));
        break;
    case 2:
        while(circularSinglyLinkedList_IO(cll));
    default:
        break;
    }
    return 0;
}

template<typename T>
bool list_IO(List<T>& list)
{
    int in;
    T x;
    cout << "1. Insert\n2. Erase\n3. Size\n4. Print\n5. Quit\n";
    cin >> in;
    switch (in)
    {
    case 1:
        cin >> x;
        list.insert(x);
        return true;
    case 2:
        cin >> x;
        list.erase(x);
        return true;
    case 3:
        cout << list.size() << endl;
        return true;
    case 4:
        list.print();
        return true;
    default:
        return false;
    }
}

template<typename T>
bool circularSinglyLinkedList_IO(CircularSinglyLinkedList<T>& cll)
{
    int in;
    T x;
    cout << "1. Push back\n2. Push front\n3. Erase\n4. Size\n5. Print\n6. Quit\n";
    cin >> in;
    switch (in)
    {
    case 1:
        cin >> x;
        cll.push_back(x);
        return true;
    case 2:
        cin >> x;
        cll.push_front(x);
        return true;
    case 3:
        cin >> x;
        cll.erase(x);
        return true;
    case 4:
        cout << cll.size() << endl;
        return true;
    case 5:
        cll.print();
        return true;
    default:
        return false;
    }
}