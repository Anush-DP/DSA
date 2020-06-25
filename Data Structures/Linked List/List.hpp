#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
struct Node
{
    T data;
    Node *next;
};

template<typename T>
class List
{
    private:
        Node<T> *head = nullptr; 
    public:
        List(): head(nullptr){}
        List(T data);
        ~List();
        void insert(T);
        void erase(T);
        int size();
        void reverse();
        void print();
};

template<typename T>
List<T>::List(T data)
{
    head = new Node<T>;
    head->data = data;
    head->next = nullptr;
}

template<typename T>
void List<T>::insert(T data)
{
    if(head == nullptr)
    {
        head = new Node<T>;
        head->data = data;
        head->next = nullptr;
        return;
    }
    auto curr = head;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }
    decltype(head) temp = new Node<T>;
    temp->next = nullptr;
    temp->data = data;
    curr->next = temp;
}

template<typename T>
List<T>::~List()
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
void List<T>::erase(T data)
{
    if(head == nullptr) return;
    auto curr = head;
    decltype(head) prev = nullptr;
    if(curr->data == data)
    {
        head = curr->next;
        delete curr;
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
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

template<typename T>
int List<T>::size()
{
    int size = 0;
    auto curr = head;
    while(curr != nullptr)
    {
        curr = curr->next;
        size++;
    }
    return size;
}

template<typename T>
void List<T>::reverse()
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
void List<T>::print()
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