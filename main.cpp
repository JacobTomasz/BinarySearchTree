/*
 * AUTHOR:  Jacob Tomaszewski
 * PURPOSE: Testing and learning about binary search trees
 */

#include <iostream>
#include "BST.h"



using namespace std;


int main() {

    BST tree;

    cout << "inserting nodes...\n";
    tree.insert(5);
    tree.insert(8);
    tree.insert(3);
    tree.insert(12);
    tree.insert(9);
    cout << "done\n\n" << endl;


    cout << "in order:\n";
    tree.display(in_order);
    cout << "\npre order:\n";
    tree.display(pre_order);
    cout << "\npost order:\n";
    tree.display(post_order);
    cout << endl;

    int x=5;
    cout << "\nsearching for values...\n";
    if (tree.search(x)) cout << x << " found in tree!\n";
    else cout << x << " NOT in tree\n";

    x=12;
    cout << "\ndeleting " << x << "...\n";
    tree.remove(x);

    cout << "new node values: \n";
    tree.display(in_order);






    return 0;
}
