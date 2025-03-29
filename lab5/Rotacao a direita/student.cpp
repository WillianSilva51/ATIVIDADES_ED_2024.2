#include <iostream>
#include <vector>

using namespace std;

void right_rotation(vector<int> &vet, int nrot)
{
    size_t size = vet.size();

    if (size == 0)
        return;

    nrot %= size;

    for (size_t i = 0; i < nrot; i++)
    {
        /*
        vet.insert(vet.begin(), vet.back());
        vet.pop_back();
        */
        int aux = vet[size - 1]; // vet.back();

        for (size_t i = size; i > 0; i--)
            vet[i] = vet[i - 1];

        vet[0] = aux;
    }
}

void show(vector<int> &vet)
{
    cout << "[ ";
    for (int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main()
{
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for (int i = 0; i < size; i++)
        cin >> vet[i];

    right_rotation(vet, nrot);
    show(vet);

    return 0;
}
