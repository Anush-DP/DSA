#include <iostream>
#include "./Linked List/singly_linked_list.hpp"
#include "Circular Linked List/circular_linked_list.hpp"
#include "Stack/stack.hpp"
using namespace std;

template<typename T>
bool singly_linked_list_IO(singly_linked_list<T>&);
template<typename T>
bool circular_linked_list_IO(circular_linked_list<T>&);
template<typename T>
bool stack_IO(stack<T>&);

int main()
{
    singly_linked_list<int> list;
    circular_linked_list<float> cll;
    stack<char> s;
    int x;
    cout << "1. Singly linked list\n";
    cout << "2. Circular singly linked list\n";
    cout << "3. Doubly linked list\n";
    cout << "4. Stack\n";
    cin >> x;
    switch (x)
    {
    case 1:
        while(singly_linked_list_IO(list));
        break;
    case 2:
        while(circular_linked_list_IO(cll));
        break;
    case 4:
        while(stack_IO(s));
        break;
    default:
        break;
    }
    return 0;
}

template<typename T>
bool singly_linked_list_IO(singly_linked_list<T>& list)
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
bool circular_linked_list_IO(circular_linked_list<T>& cll)
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

template<typename T>
bool stack_IO(stack<T>& s)
{
    int in;
    T x;
    cout << "1. Push\n2. Pop\n3. Top\n4. Size\n5. Quit\n";
    cin >> in;
    switch (in)
    {
    case 1:
        cin >> x;
        s.push(x);
        return true;
    case 2:
        s.pop();
        return true;
    case 3:
        cout << s.top() << endl;
        return true;
    case 4:
        cout << s.size() << endl;
        return true;
    default:
        return false;
    }
}