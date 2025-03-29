#include <iostream>

using namespace std;

/**
 * @brief Calcula o número de maneiras de subir uma escada com um dado número de degraus.
 *
 * Esta função utiliza uma abordagem recursiva para determinar o número de maneiras
 * de subir uma escada com um número específico de degraus. A função considera que
 * é possível subir 1 ou 3 degraus de cada vez.
 *
 * @param degraus O número de degraus da escada.
 * @return O número de maneiras de subir a escada.
 *
 * @note Se o número de degraus for 1 ou 2, há apenas uma maneira de subir a escada.
 *       Se o número de degraus for 3, há duas maneiras de subir a escada.
 *       Para um número maior de degraus, a função calcula a soma das maneiras de
 *       subir a escada com (degraus - 1) e (degraus - 3) degraus.
 */
int escada(const int &degraus)
{
    if (degraus == 1 || degraus == 2)
        return 1;

    if (degraus == 3)
        return 2;

    return escada(degraus - 1) + escada(degraus - 3);
}

int main()
{
    int degraus;

    cin >> degraus;

    cout << escada(degraus) << endl;

    return 0;
}