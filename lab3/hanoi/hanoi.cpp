#include <iostream>

using namespace std;

/**
 * @brief Imprime os passos para solução da Torre de Hanoi.
 *  @param qte: números de discos que devem ser movidos da torre inicial para a torre final
 *  @param ini: torre que é considerada como torre inicial
 *  @param aux: torre que é considerada como torre auxiliar
 *  @param fim: torre que é considerada como torre final
 * @note 
 *   Pseudocódigo:
 *   se existe apenas 1 disco para mover
 *     mova este único disco da torre inicial para a torre final
 *   senão
 *    recursivamente mova qte-1 discos da torre inicial para a torre auxiliar
 *    mova o disco que sobrou da torre inicial para a torre final
 *      recursivamente mova qte-1 discos da torre auxiliar para a torre final
 */
void hanoi(const int &qte, const char &ini, const char &aux, const char &fim)
{
    if (qte == 1)
        cout << ini << " -> " << fim << endl;

    else
    {
        hanoi(qte - 1, ini, fim, aux);

        cout << ini << " -> " << fim << endl;

        hanoi(qte - 1, aux, ini, fim);
    }
}

int main()
{
    int qte;

    cin >> qte;

    hanoi(qte, 'A', 'B', 'C');

    return 0;
}