#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Pos
{
    size_t l;
    size_t c;
};

// retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p, vector<string> &mat, vector<vector<bool>> &visitado)
{
    vector<Pos> vizinhos = {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};

    for (size_t i = 0; i < vizinhos.size(); i++)
    {
        if (vizinhos[i].l >= mat.size() || vizinhos[i].c >= mat[0].size() || mat[vizinhos[i].l][vizinhos[i].c] != ' ' || visitado[vizinhos[i].l][vizinhos[i].c] == true)
        {
            vizinhos.erase(vizinhos.begin() + i);
            i--;
        }
    }

    return vizinhos;
}

/**
 * marque e empilhe a posição inicio
 * inicie a pilha com esse elemento
 *
 * enquanto a pilha não estiver vazia faça
 *    pegue topo da fila
 *
 *    se ele for o destino
 *          retorne
 *
 * faça uma lista com todos os vizinhos de topo que ainda não foram percorridos
 *      se lista eh vazia
 *          desempilhe
 *      senão
 *          escolha um dos vizinhos
 *          marque
 *          empilhe
 */
void caminho(vector<string> &mat, Pos inicio, Pos fim)
{
    stack<Pos> pilha;
    mat[inicio.l][inicio.c] = '.';

    vector<vector<bool>> visitado(mat.size(), vector<bool>(mat[0].size(), false));

    pilha.push(inicio);
    visitado[inicio.l][inicio.c] = true;

    while (!pilha.empty())
    {
        Pos topo = pilha.top();

        if (topo.l == fim.l && topo.c == fim.c)
            return;

        vector<Pos> vizinhos = get_vizinhos(topo, mat, visitado);

        cout << vizinhos.size() << endl;
        if (vizinhos.empty())
        {
            pilha.pop();
            mat[topo.l][topo.c] = ' ';
        }
        else
        {
            Pos vizinho = vizinhos[0];
            mat[vizinho.l][vizinho.c] = '.';
            visitado[vizinho.l][vizinho.c] = true;
            pilha.push(vizinho);
        }

        for (string line : mat)
            cout << line << endl;

        system("pause");
    }
}

int main()
{
    size_t nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); // começa com nl strings ""
    getchar();                  // remove \n after nc
    Pos inicio, fim;

    // carregando matriz
    for (size_t i = 0; i < nl; i++)
        getline(cin, mat[i]);

    // procurando inicio e fim e colocando ' ' nas posições iniciais
    for (size_t l = 0; l < nl; l++)
    {
        for (size_t c = 0; c < nc; c++)
        {
            if (mat[l][c] == 'I')
            {
                mat[l][c] = ' ';
                inicio = Pos{l, c};
            }
            if (mat[l][c] == 'F')
            {
                mat[l][c] = ' ';
                fim = Pos{l, c};
            }
        }
    }

    caminho(mat, inicio, fim);

    for (string line : mat)
        cout << line << endl;
    cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;

    return 0;
}