#include <iostream>
#include <vector>

using namespace std;

void scan(vector<int> &pecas)
{
    for (int &peca : pecas)
        cin >> peca;
}

bool ordenado(vector<int> &pecas)
{
    for (size_t i = 1; i < pecas.size(); i++)
        if (pecas[i - 1] > pecas[i])
            return false;

    return true;
}

void dominos(vector<int> &pecas)
{
    if (ordenado(pecas))
        cout << "ok" << endl;

    else
        cout << "precisa de ajuste" << endl;
}

/**
 * Leia um vetor de tamanho n (quantidade de dominós) , e diga se ele está ordenado de forma crescente.
 *
 * Entrada:
 *   O número n (0 < n <= 50) de dominós.
 *   A altura (inteira) de cada dominó.
 *
 * Saída:
 *   "ok" caso o vetor esteja ordenado.
 *   "precisa de ajuste" caso o vetor esteja desordenado.
 */
int main()
{
    vector<int> pecas([]() { // Função para ler o tamanho do vetor desse vetor muito bacana
        size_t tam;
        cin >> tam;
        return tam;
    }());

    scan(pecas);

    dominos(pecas);

    return 0;
}