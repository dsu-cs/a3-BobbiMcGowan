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
   int traversal_data;
   Node<T> *succParent;
   Node<T> succ;
   vector<T> vec;
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

       return NULL;

       inOrder(root->get_left());
       cin>>root->vec &traversal_data;
       inOrder(root->get_right());
       
}
    return vec;
}

template <class T>
std::vector<T> *BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;

    if(root == NULL)
        return NULL;
        
        cin>>root->vec &traversal_data;
        preOrder(root->get_left());
        preOrder(root->get_right());

    return vec;
}

template <class T>
std::vector<T> *BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    if(root == NULL)
      return NULL;

      postOrder(root->get_left());
      postOrder(root->get_right());
      cin>>root->vec &traversal_data;

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
        tmp->data = new_data;
        tmp->left_node_ptr = NULL;
        tmp->right_node_ptr= NULL;
        return tmp;
    }
   else
  {
    
      root->set_left() = insertHelper(new_data, node->left_node_ptr);
  }
}

template <class T>
Node<T> *BST<T>::search(T val)
{
    if(root == NULL)
    return NULL;

    if(root->val == val)
    return root;
    
    if(root->val<val)
    return search(root->get_right(),val);

    else
    {
        return search(root->get_left(), val);
    }
    
}

template <class T>
void BST<T>::remove(T val)
{
    if(root == NULL)
    return;

    if(root->val > val)
    {
        root->get_left() = remove(root->left_node_ptr,val);
        return;
    }

    else if(root->val < val)
    {
        root->get_right() = remove(root->right_node_ptr, val);
        return;
    }

    if(root->get_left() == NULL)
    {
        Node<T> *tmp = root->set_right();
        delete root;
        return;
    }
    else if(root->get_right() == NULL)
    {
        Node<T> *tmp = root->set_left();
        delete root;
        return;
    }
    
    else
    {
        Node<T> *succParent = root->get_right();

        Node<T> *succ = root->set_right();

        While(succ->get_left() != NULL);
        {
            succParent = succ;
            succ = succ->set_left();
        }

        succParent->set_left() = succ->set_right();

        root->set_data() = succ->get_data();

        delete succ;
        return;
    }
    

}

template <class T>
int BST<T>::get_size()
{
    if(root == NULL)
    return 0;

    else
    {
       return(node_count(root->get_left()) + 1 + node_count(root->get_right()));
    }
}