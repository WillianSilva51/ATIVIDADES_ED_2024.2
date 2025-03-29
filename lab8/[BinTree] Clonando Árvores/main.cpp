#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    Tree bt1(line1);
    Tree bt2(line2);
    Tree *bt3 = bt1.clone();

    bt1.bshow();
    bt2.bshow();
    bt3->bshow();

    if (bt1.identical(bt3))
        cout << "identica" << endl;
    else
        cout << "diferente" << endl;
    if (bt2.identical(bt3))
        cout << "identica" << endl;
    else
        cout << "diferente" << endl;
    if (bt1.identical(&bt2))
        cout << "identica" << endl;
    else
        cout << "diferente" << endl;
    return 0;
}