/*
 * AUTHOR:  Jacob Tomaszewski
 * PURPOSE: Testing and learning about binary search trees
 */

#include <iostream>
#include <string>
#include "BST.h"



using namespace std;


int main() {

    BST<string> tree;

    cout << "inserting nodes...\n";
//    tree.insert(5);
//    tree.insert(8);
//    tree.insert(3);
//    tree.insert(12);
//    tree.insert(9);

    tree.insert("asdf");
    tree.insert("fdsa");
    tree.insert("ksksk");
    tree.insert("aa");
    tree.insert("pppp");

    cout << "done\n\n" << endl;


    cout << "in order:\n";
    tree.display(in_order);
    cout << "\npre order:\n";
    tree.display(pre_order);
    cout << "\npost order:\n";
    tree.display(post_order);
    cout << endl;

    //int x=5;
    string x="aa";
    cout << "\nsearching for values...\n";
    if (tree.search(x)) cout << x << " found in tree!\n";
    else cout << x << " NOT in tree\n";
    cout << "\ndeleting " << x << "...\n";
    tree.remove(x);
    cout << "new node values: \n";
    tree.display(in_order);






    return 0;
}
