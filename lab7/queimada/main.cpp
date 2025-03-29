#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * verifique a primeira posição e queime-o
 * inicie a pilha com esse elemento
 * enquanto a pilha não estiver vazia faça
 *      pegue topo da pilha
 *
 * faça uma lista com todos os vizinhos de topo que podem ser queimados
 *       se lista eh vazia
 *          desempilhe
 *      senão
 *          escolha um dos vizinhos
 *          queime
 *          empilhe
 * */
void queima(vector<vector<char>> &floresta, int i, int j)
{
    if (floresta[i][j] == '#')
        floresta[i][j] = 'o';

    else if (floresta[i][j] == '.')
        return;

    stack<pair<size_t, size_t>> pilha;
    pilha.push({i, j});

    while (!pilha.empty())
    {
        auto topo = pilha.top();

        vector<pair<size_t, size_t>> vizinhos;

        if (topo.first > 0 && floresta[topo.first - 1][topo.second] == '#')
            vizinhos.push_back({topo.first - 1, topo.second});

        if (topo.first < floresta.size() - 1 && floresta[topo.first + 1][topo.second] == '#')
            vizinhos.push_back({topo.first + 1, topo.second});

        if (topo.second > 0 && floresta[topo.first][topo.second - 1] == '#')
            vizinhos.push_back({topo.first, topo.second - 1});

        if (topo.second < floresta[0].size() - 1 && floresta[topo.first][topo.second + 1] == '#')
            vizinhos.push_back({topo.first, topo.second + 1});

        if (vizinhos.empty())
            pilha.pop();

        else
        {
            auto vizinho = vizinhos.back();
            floresta[vizinho.first][vizinho.second] = 'o';
            pilha.push(vizinho);
        }
    }
}

int main()
{
    int n, m, i, j;

    cin >> n >> m >> i >> j;
    cin.ignore();

    vector<vector<char>> floresta(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> floresta[i][j];
        cin.ignore();
    }

    queima(floresta, i, j);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << floresta[i][j];
        cout << endl;
    }

    return 0;
}