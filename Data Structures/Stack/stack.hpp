#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

template<typename T>
class stack
{
    private:
        std::vector<T> stack_vector;
        int stack_top;
        int stack_size;
    public:
        stack(): stack_top(-1), stack_size(0){}
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
    ++stack_size;
    ++stack_top;
}

template<typename T>
void stack<T>::pop()
{
    if(stack_size == 0) return;
    stack_vector.pop_back();
    --stack_size;
    --stack_top;
}

template<typename T>
T stack<T>::top()
{
    if(stack_size == 0) throw 1;
    return stack_vector[stack_top];
}

template<typename T>
int stack<T>::size()
{
    return stack_size;
}

template<typename T>
bool stack<T>::empty()
{
    return stack_size == 0;
}

#endif
