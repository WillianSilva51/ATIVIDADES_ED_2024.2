#include <iostream>
#include <iomanip>

using namespace std;

double fat(int iterador, double result)
{
    if (iterador == 0)
        return result;

    return fat(iterador - 1, result * iterador);
}

double euler(int &numero)
{
    double soma = 1.0f;

    for (int i = 1; i <= numero; i++)
        soma += (1.0f / fat(i, 1));

    return soma;
}

int main()
{
    int numero = [&numero]() -> int
    { cin >> numero;
    return numero; }(); // usei isso pq aprendi a fazer isso hoje, é muito legal

    cout << fixed << setprecision(6) << euler(numero) << endl;

    return 0;
}