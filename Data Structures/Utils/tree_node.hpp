#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

template<typename T>
struct tree_node
{
    T data;
    tree_node *left;
    tree_node *right;
};

#endif