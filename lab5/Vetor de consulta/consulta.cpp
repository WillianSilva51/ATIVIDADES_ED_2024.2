#include <iostream>
#include <vector>

using namespace std;

void lerVector(vector<string> &v)
{
    for (size_t i = 0; i < v.size(); i++)
        cin >> v[i];
}

template <typename T>
void imprimirVector(const vector<T> &v)
{
    for (size_t i = 0, tam = v.size(); i < tam; i++)
        cout << v[i] << ((i + 1 < tam) ? " " : "");
    cout << endl;
}

void igual(vector<string> &strings, vector<string> &consultas)
{
    vector<int> cont(consultas.size(), 0);

    for (size_t i = 0, tam = consultas.size(); i < tam; i++)
        for (size_t j = 0, tam2 = strings.size(); j < tam2; j++)
            if (consultas[i] == strings[j])
                cont[i]++;

    imprimirVector(cont);
}

int main()
{
    size_t tamS, tamC;

    cin >> tamS;
    vector<string> strings(tamS);
    lerVector(strings);

    cin >> tamC;
    vector<string> consultas(tamC);
    lerVector(consultas);

    igual(strings, consultas);

    return 0;
}