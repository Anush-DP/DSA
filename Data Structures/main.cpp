#include <iostream>
#include "./Linked List/List.hpp"
using namespace std;

int main()
{
    List<int> list;
    cout << "Size: " << list.size() << endl;
    list.insert(1);
    list.insert(2);
    list.insert(5);
    list.print();
    cout << "Size: " << list.size() << endl;
    list.erase(3);
    cout << "Size: " << list.size() << endl;
    list.print();
    list.reverse();
    list.print();
    return 0;
}