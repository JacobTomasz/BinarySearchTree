#pragma once
#include <iostream>
using namespace std;

enum opt {in_order, pre_order, post_order}; //display tree order options


class BST {
private:
    struct Node {
        int data;                // the value in the node
        Node *left, *right;      // left and right sided child nodes?
    };

    Node* root;                         // pointer to the root node
    void insertNode(Node*&, Node*&);    // insert node
    void removeNode(int, Node*&);       // find and delete node
    static void makeDeletion(Node*&);   // deletes node and reattaches node's subtree's
    void destroy_tree(Node*);           // recursively delete all nodes in the tree

    //display functions
    void displayInOrder(Node*) const;
    void displayPreOrder(Node*) const;
    void displayPostOrder(Node*) const;

public:
    BST();
    //BST(int); //parameterized constructor
    ~BST();
    void insert(int);           // insert value
    bool search(int);           // search for value
    void remove(int);           // delete value
    void display(opt) const;    // display tree
};