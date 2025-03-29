#include <iostream>
#include <vector>

using namespace std;

const void lerVetor(vector<int> &valores, const size_t &i = 0)
{
    if (i >= valores.size())
        return;

    cin >> valores[i];

    lerVetor(valores, i + 1);
}

const void print(const vector<int> &valores, const int &n = 0)
{
    if (n == valores.size())
    {
        cout << "]" << endl;
        return;
    }

    if (n == 0)
        cout << "[";

    cout << valores[n];

    if (n < valores.size() - 1)
        cout << ", ";

    print(valores, n + 1);
}

/* Invertido
void triangulosInv(vector<int> &valores, const size_t &i = 0)
{
    if (i == 0)
        print(valores);

    if (i >= valores.size())
    {
        valores.resize(valores.size() - 1);
        triangulos(valores);
    }

    if (valores.size() == 1)
        return;

    valores[i] = valores[i] + valores[i + 1];

    triangulos(valores, i + 1);
}
*/

/**
 * @brief Função auxiliar que modifica um vetor de inteiros, somando elementos adjacentes.
 *
 * Esta função recursiva percorre o vetor 'valores' a partir do índice 'i' (inicialmente 0),
 * somando cada elemento com o próximo elemento e armazenando o resultado no próprio vetor.
 * Quando o índice 'i' atinge o tamanho do vetor, a função reduz o tamanho do vetor em uma unidade.
 *
 * @param valores Vetor de inteiros a ser modificado.
 * @param i Índice atual da iteração (padrão é 0).
 */
void triangulosAux(vector<int> &valores, const size_t &i = 0)
{
    if (i >= valores.size())
    {
        valores.resize(valores.size() - 1);
        return;
    }

    valores[i] = valores[i] + valores[i + 1];

    triangulosAux(valores, i + 1);
}

/**
 * @brief Função que processa uma lista de valores inteiros para formar triângulos.
 *
 * Esta função recebe um vetor de inteiros e aplica uma função auxiliar para processar
 * os valores. Em seguida, chama a si mesma recursivamente até que o vetor tenha apenas
 * um elemento. Após a recursão, imprime os valores processados.
 *
 * @param valores Vetor de inteiros a ser processado.
 */
void triangulos(vector<int> valores)
{
    if (valores.size() == 1)
        return;

    triangulosAux(valores);

    triangulos(valores);

    print(valores);
}

int main()
{
    vector<int> valores([]()
                        {
        int tam;
        cin >> tam;
        return tam; }());

    lerVetor(valores);

    triangulos(valores);

    print(valores);

    return 0;
}