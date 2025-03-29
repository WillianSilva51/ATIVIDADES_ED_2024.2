#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    float valor;
    float chute;
    char escolha;
} MERCADO;

void limparCin()
{
    cin.clear();
    cin.ignore();
}

void scan(vector<MERCADO> &produtos)
{
    for (auto &prod : produtos)
        cin >> prod.valor;

    for (auto &prod : produtos)
        cin >> prod.chute;

    for (auto &prod : produtos)
    {
        cin >> prod.escolha;
        limparCin();
    }
}

string ganhador(const int &jogador1, const int &jogador2)
{
    if (jogador1 > jogador2)
        return "primeiro";

    else if (jogador1 < jogador2)
        return "segundo";

    return "empate";
}

void maiorOUmenor(vector<MERCADO> &produtos)
{
    int jogador1 = 0, jogador2 = 0;

    for (const auto &produto : produtos)
    {
        if (produto.valor == produto.chute)
            jogador1++;

        if (produto.escolha == 'm')
        {
            if (produto.valor < produto.chute)
                jogador2++;

            else if (produto.valor > produto.chute)
                jogador1++;
        }

        else
        {
            if (produto.valor > produto.chute)
                jogador2++;

            else if (produto.valor < produto.chute)
                jogador1++;
        }
    }

    cout << ganhador(jogador1, jogador2) << endl;
}

int main()
{
    vector<MERCADO> produtos([]()
                             {
        size_t tam;
        cin >> tam;
        return tam; }());

    scan(produtos);

    maiorOUmenor(produtos);

    return 0;
}