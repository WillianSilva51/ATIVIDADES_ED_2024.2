#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    string line;
    getline(cin, line);
    Tree bt(line);
    int value;
    cin >> value;
    bt.bshow();
    string path = bt.find_path(value);
    cout << path << endl;
    return 0;
}