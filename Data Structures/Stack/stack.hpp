#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

template<typename T>
class stack
{
private:
    std::vector<T> stack_vector;
public:
    ~stack();
    void push(T data);
    void pop();
    T top() const;
    int size() const;
    bool empty() const;
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
}

template<typename T>
void stack<T>::pop()
{
    if(stack_vector.empty()) return;
    stack_vector.pop_back();
}

template<typename T>
T stack<T>::top() const
{
    if(stack_vector.empty()) throw 1;
    return stack_vector[stack_vector.size() - 1];
}

template<typename T>
int stack<T>::size() const
{
    return stack_vector.size();
}

template<typename T>
bool stack<T>::empty() const
{
    return stack_vector.empty();
}

#endif
