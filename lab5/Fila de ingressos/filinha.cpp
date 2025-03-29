#include <iostream>
#include <vector>

using namespace std;

void lerVector(vector<int> &vet)
{
    for (size_t i = 0, tam = vet.size(); i < tam; i++)
        cin >> vet[i];
}

void imprimirVector(const vector<int> &vet)
{
    for (size_t i = 0, tam = vet.size(); i < tam; i++)
        cout << vet[i] << " ";

    cout << endl;
}

void saiuDaFila(vector<int> &fila, vector<int> &retirantes)
{
    for (size_t i = 0, tam = fila.size(); i < tam; i++)
    {
        for (size_t j = 0, tam2 = retirantes.size(); j < tam2; j++)
        {
            if (fila[i] == retirantes[j])
                fila.erase(fila.begin() + i);
        }
    }

    imprimirVector(fila);
}

int main()
{
    size_t n, m;

    cin >> n;
    vector<int> fila(n);
    lerVector(fila);

    cin >> m;
    vector<int> retirantes(m);
    lerVector(retirantes);

    saiuDaFila(fila, retirantes);

    return 0;
}