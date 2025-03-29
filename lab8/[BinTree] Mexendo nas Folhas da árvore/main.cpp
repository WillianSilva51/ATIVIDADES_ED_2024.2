#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    string line;
    int value;
    getline(cin, line);
    cin >> value;
    Tree bt(line);
    cout << bt.count_leaves() << endl;
    bt.bshow();
    bt.delete_leaves();
    bt.bshow();
    bt.preorder();
    cout << "\n";
    bt.inorder();
    cout << "\n";
    bt.delete_leaves_with_value(value);
    bt.preorder();
    cout << "\n";
    bt.inorder();
    return 0;
}