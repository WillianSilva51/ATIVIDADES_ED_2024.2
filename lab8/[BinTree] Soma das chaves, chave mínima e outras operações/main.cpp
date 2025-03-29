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
    cout << bt.min_key() << " " << bt.sum_keys() << endl;
    cout << bt.total_internal_nodes() << " " << bt.um_filho() << endl;
    return 0;
}