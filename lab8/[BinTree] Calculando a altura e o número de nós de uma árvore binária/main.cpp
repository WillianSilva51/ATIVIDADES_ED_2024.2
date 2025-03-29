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

    bt.bshow();

    cout << bt.height() << " " << bt.size() << endl;

    return 0;
}