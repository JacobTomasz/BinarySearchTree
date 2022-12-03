//
// Created by Jacob on 12/2/2022.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    destroy_tree(root);
}

void BST::insertNode(BST::Node *&nptr, BST::Node *&newNode) {
    if (nptr == nullptr)
        nptr = newNode;
    else if (newNode->data < nptr->data)
        insertNode(nptr->left, newNode);
    else
        insertNode(nptr->right, newNode);
}

void BST::removeNode(int val, BST::Node *&nptr) {
    if (val < nptr->data)
        removeNode(val, nptr->left);
    else if (val > nptr->data)
        removeNode(val, nptr->right);
    else
        makeDeletion(nptr);
}

void BST::makeDeletion(BST::Node *&nptr) {
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


void BST::destroy_tree(BST::Node *nptr) {
    if (nptr) {
        if (nptr->left)
            destroy_tree(nptr->left);
        if (nptr->right)
            destroy_tree(nptr->right);
        delete nptr;
    }
}

void BST::insert(int val) {
    Node *newNode = nullptr;
    newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    insertNode(root, newNode);
}

bool BST::search(int val) {
    Node *nptr = root;
    while (nptr) {
        if (nptr->data == val) return true;
        else if (val < nptr->data) nptr = nptr->left;
        else nptr = nptr->right;
    }
    return false;
}


void BST::remove(int val) {
    removeNode(val, root);
}


void BST::displayInOrder(BST::Node *nptr) const {
    if (nptr) {
        displayInOrder(nptr->left);
        cout << nptr->data << endl;
        displayInOrder(nptr->right);
    }

}

void BST::displayPreOrder(BST::Node *nptr) const {
    if (nptr) {
        cout << nptr->data << endl;
        displayPreOrder(nptr->left);
        displayPreOrder(nptr->right);
    }
}

void BST::displayPostOrder(BST::Node *nptr) const {
    if (nptr) {
        displayPostOrder(nptr->left);
        displayPostOrder(nptr->right);
        cout << nptr->data << endl;
    }
}

void BST::display(opt sel) const {
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












