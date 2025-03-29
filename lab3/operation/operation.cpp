#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const void print(const vector<int> &valores, const int &n = 0)
{
    if (n == valores.size())
    {
        cout << "]" << endl;
        return;
    }

    if (n == 0)
        cout << "[ ";

    cout << valores[n] << " ";

    print(valores, n + 1);
}

const void printInv(const vector<int> &valores, const int &n)
{
    if (n < 0)
    {
        cout << "]" << endl;
        return;
    }

    if (n == valores.size() - 1)
        cout << "[ ";

    cout << valores[n] << " ";

    printInv(valores, n - 1);
}

int soma(const vector<int> &valores, const int &n = 0)
{
    return n == valores.size() ? 0 : valores[n] + soma(valores, n + 1);
}

int multi(const vector<int> &valores, const int &i, const int &n = 1)
{
    return i < 0 ? n : multi(valores, i - 1, n * valores[i]);
}

int minimo(const vector<int> &valores, const int &n)
{
    if (n == 1)
        return valores[0];

    int min = minimo(valores, n - 1);

    return min < valores[n - 1] ? min : valores[n - 1];
}

void inverter(vector<int> &valores, const size_t &fim, const size_t init = 0)
{
    if (init < fim)
    {
        swap(valores[init], valores[fim]);

        /*
        int aux = valores[init];
        valores[init] = valores[fim];
        valores[fim] = aux;
        */

        inverter(valores, fim - 1, init + 1);
    }
}

int main()
{
    string valores;

    getline(cin, valores);

    stringstream ss(valores);

    int value;
    vector<int> vetor;

    while (ss >> value)
        vetor.push_back(value);

    cout << "vet : ";
    print(vetor);

    cout << "rvet : ";
    printInv(vetor, vetor.size() - 1);

    cout << "sum : " << soma(vetor) << endl;

    cout << "mult : " << multi(vetor, vetor.size() - 1) << endl;

    cout << "min : " << minimo(vetor, vetor.size()) << endl;

    inverter(vetor, vetor.size() - 1);
    cout << "inv : ";
    print(vetor);

    return 0;
}