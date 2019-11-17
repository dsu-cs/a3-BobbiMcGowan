#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"
#include <vector>
using namespace std;

template <class T>
class BST
{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);

private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    //prototype for helper
   Node<T> *insertHelper(T, Node<T> *node);
};

template <class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template <class T>
BST<T>::~BST()
{
    root = NULL;
    while (root != NULL)
    {
        remove(root->get_data());
    }
}
//std::vector<T> *inorder(void);
template <class T>
std::vector<T> *BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;
{
   if(root==NULL)

       return;

       inOrder(root->left);//should N<T> be root?
       cout<<root->data<< " ";
       inOrder(root->right);

}
    return vec;
}

template <class T>
std::vector<T> *BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;

    if(root == NULL)
        return;
        
        cout<<root->data<< " ";
        preOrder(root->left);
        preOrder(root->right);

    return vec;
}

template <class T>
std::vector<T> *BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    if(root == NULL)
      return;

      postOrder(root->left);
      postOrder(root->right);
      cout<<root->data<< " ";

    return vec;
}

template <class T>
void BST<T>::insert(T new_data)
{
  root = insertHelper(new_data, root);
}
template <class T>
Node<T> *BST<T>::insertHelper(T new_data, Node<T> *node)
{
    if (root == NULL)
    {
        Node<T> *tmp = new Node<T>;
        tmp->new_data = new_data;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    else
    {
    
        root->left = insertHelper(new_data, root->left);
    }
}

template <class T>
Node<T> *BST<T>::search(T val)
{
    if(root == NULL)
    return;

    if(root->val == val)
    return root;
    
    if(root->val<val)
    return search(root->right,val);

    else
    {
        return search(root->left, val);
    }
    


}

template <class T>
void BST<T>::remove(T val)
{
}

template <class T>
int BST<T>::get_size()
{
}