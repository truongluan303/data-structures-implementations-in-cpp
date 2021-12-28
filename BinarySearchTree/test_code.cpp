#include <iostream>

#include "binary_search_tree.cpp"


using namespace std;


int main()
{
    BinarySearchTree<int> bst;

    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.add(10);
    bst.add(4);
    bst.add(2);

    return 0;
}
