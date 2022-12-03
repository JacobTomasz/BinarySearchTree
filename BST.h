#pragma once
#include <iostream>
using namespace std;

enum opt {in_order, pre_order, post_order}; //display tree order options

template <class T>
class BST {
private:
    struct Node {
        T data;                 // the value in the node
        Node *left, *right;     // left and right sided child nodes?
    };

    Node *root;                         // pointer to the root node
    void insertNode(Node*&, Node*&);    // insert node
    void removeNode(T, Node*&);         // find and delete node
    static void makeDeletion(Node*&);   // deletes node and reattaches node's subtree's
    void destroy_tree(Node*);           // recursively delete all nodes in the tree

    //display functions
    void displayInOrder(Node*) const;
    void displayPreOrder(Node*) const;
    void displayPostOrder(Node*) const;

public:

    BST();                      // constructor
    ~BST();                     // destructor
    void insert(T);             // insert value
    bool search(T);             // search for value
    void remove(T);             // delete value
    void display(opt) const;    // display tree
};


///DEFINITIONS

template<class T>
BST<T>::BST() {
    root = nullptr;
}

template<class T>
BST<T>::~BST() {
    destroy_tree(root);
}

template <class T>
void BST<T>::insertNode(Node *&nptr, Node *&newNode) {
    if (nptr == nullptr)
        nptr = newNode;
    else if (newNode->data < nptr->data)
        insertNode(nptr->left, newNode);
    else
        insertNode(nptr->right, newNode);
}

template <class T>
void BST<T>::removeNode(T val, Node *&nptr) {
    if (val < nptr->data)
        removeNode(val, nptr->left);
    else if (val > nptr->data)
        removeNode(val, nptr->right);
    else
        makeDeletion(nptr);
}

template <class T>
void BST<T>::makeDeletion(Node *&nptr) {
    Node *tmp; //= nullptr;
    if (nptr == nullptr)
        cout << "\nERROR: cannot delete empty node\n";
    else if (nptr->right == nullptr) {
        tmp = nptr;
        nptr = nptr->left;
        delete tmp;
    }
    else if (nptr->left == nullptr) {
        tmp = nptr;
        nptr = nptr->right;
        delete tmp;
    }
    else {
        tmp = nptr->right;
        while (tmp->left)
            tmp = tmp->left;
        tmp->left = nptr->left;
        tmp = nptr;
        nptr = nptr->right;
        delete tmp;
    }
}

template <class T>
void BST<T>::destroy_tree(Node *nptr) {
    if (nptr) {
        if (nptr->left)
            destroy_tree(nptr->left);
        if (nptr->right)
            destroy_tree(nptr->right);
        delete nptr;
    }
}

template <class T>
void BST<T>::insert(T val) {
    Node *newNode = nullptr;
    newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    insertNode(root, newNode);
}

template <class T>
bool BST<T>::search(T val) {
    Node *nptr = root;
    while (nptr) {
        if (nptr->data == val) return true;
        else if (val < nptr->data) nptr = nptr->left;
        else nptr = nptr->right;
    }
    return false;
}

template <class T>
void BST<T>::remove(T val) {
    removeNode(val, root);
}

template <class T>
void BST<T>::displayInOrder(Node *nptr) const {
    if (nptr) {
        displayInOrder(nptr->left);
        cout << nptr->data << endl;
        displayInOrder(nptr->right);
    }

}
template <class T>
void BST<T>::displayPreOrder(Node *nptr) const {
    if (nptr) {
        cout << nptr->data << endl;
        displayPreOrder(nptr->left);
        displayPreOrder(nptr->right);
    }
}

template <class T>
void BST<T>::displayPostOrder(Node *nptr) const {
    if (nptr) {
        displayPostOrder(nptr->left);
        displayPostOrder(nptr->right);
        cout << nptr->data << endl;
    }
}

template <class T>
void BST<T>::display(opt sel) const {
    switch (sel) {
        case in_order:
            displayInOrder(root);
            break;
        case pre_order:
            displayPreOrder(root);
            break;
        case post_order:
            displayPostOrder(root);
            break;
        default:
            cout << "\nERROR: invalid display option\n" << endl;
    }

}
