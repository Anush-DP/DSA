#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

template<typename T>
class stack
{
private:
    std::vector<T> stack_vector;
    int stack_top;
public:
    stack(): stack_top(-1){}
    ~stack();
    void push(T data);
    void pop();
    T top();
    int size();
    bool empty();
};

template<typename T>
stack<T>::~stack()
{
    stack_vector.clear();
}

template<typename T>
void stack<T>::push(T data)
{
    stack_vector.push_back(data);
    ++stack_top;
}

template<typename T>
void stack<T>::pop()
{
    if(empty()) return;
    stack_vector.pop_back();
    --stack_top;
}

template<typename T>
T stack<T>::top()
{
    if(empty()) throw 1;
    return stack_vector[stack_top];
}

template<typename T>
int stack<T>::size()
{
    return stack_top + 1;
}

template<typename T>
bool stack<T>::empty()
{
    return stack_top == -1;
}

#endif
