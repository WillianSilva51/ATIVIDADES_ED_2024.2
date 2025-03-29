#include <iostream>

using namespace std;

/**
 * @author Willian
 *
 * @brief Resolve o problema das Torres de Hanói com 4 pinos.
 *
 * Esta função resolve o problema das Torres de Hanói utilizando quatro pinos em vez dos tradicionais três.
 * O objetivo é mover 'n' discos da torre de origem para a torre final, utilizando duas torres auxiliares.
 *
 * @param n O número de discos a serem movidos.
 * @param origem O pino de origem de onde os discos serão movidos.
 * @param aux1 O primeiro pino auxiliar.
 * @param aux2 O segundo pino auxiliar.
 * @param final O pino final para onde os discos serão movidos.
 */
void hanoiDe4Pernas(const int &n, const char &origem, const char &aux1, const char &aux2, const char &final)
{
    if (n == 0)
        return;

    if (n == 1)
        cout << origem << " -> " << final << endl;
    else
    {
        int k{n / 2};

        hanoiDe4Pernas(k, origem, final, aux2, aux1);

        hanoiDe4Pernas(n - k, origem, aux2, aux1, final);

        hanoiDe4Pernas(k, aux1, origem, aux2, final);
    }
}

int main()
{
    int n;

    cout << "Digite o numero de discos: ";
    cin >> n;

    cout << "Para resolver origem Torre de Hanoi com " << n << " discos, siga os passos abaixo:" << endl;

    hanoiDe4Pernas(n, 'A', 'B', 'C', 'D');

    return 0;
}