#include <iostream>
#include "queue.hpp"

using namespace std;

int main()
{
    queue q;
    size_t count;

    cin >> count;

    for (size_t i = 0; i < count; i++)
    {
        int choice;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int x;
            cin >> x;
            q.push(x);
            break;

        case 2:
            q.pop();
            break;

        case 3:
            cout << q.front() << endl;
            break;

        default:
            cout << "Escolha Invalida" << endl;
            break;
        }
    }

    return 0;
}