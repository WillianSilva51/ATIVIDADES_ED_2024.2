#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void prencherVector(vector<int> &v)
{
    for (size_t i = 0, tam = v.size(); i < tam; i++)
        v[i] = i + 1;
}

void printVector1(const vector<int> &v, const size_t &iniciador)
{
    ostringstream oss;

    oss << "[ ";

    for (size_t i = 0, tam = v.size(); i < tam; i++)
    {
        if (v[i] != 0)
            oss << v[i];

        oss << (i == iniciador ? "> " : " ");
    }
    oss << "]";

    cout << oss.str() << endl;
}

void proxVivo(const vector<int> &v, size_t &iniciador, const size_t &tam)
{
    while (true)
    {
        if (iniciador >= tam - 1)
            iniciador = 0;

        if (v[iniciador] != 0)
            return;

        iniciador++;
    }
}

/*
marcando os elementos que morrem.
toda vez que alguém morrer, marque 0 no vetor
procure pelo próximo elemento vivo a direita
int elementos[size];
//matar equivale a fazer
vivos[pos] = false;
//o próximo vivo seria uma busca pelo próximo vivo depois de pos
int prox = procurar_vivo(elementos, size, pos);
*/
void josephus1(vector<int> &v, size_t &iniciador)
{
    size_t count{0};
    size_t tam = v.size();

    while (true)
    {
        printVector1(v, iniciador);

        for (size_t i = 0; i < tam; i++)
            if (v[i] != 0)
                count++;

        if (count == 1)
            break;

        v[iniciador++] = 0;

        proxVivo(v, iniciador, tam);
    }
}

/*
void printVector2(const vector<int> &v, size_t &iniciador)
{
    ostringstream oss;

    oss << "[ ";

    for (size_t i = 0, tam = v.size(); i < tam; ++i)
        oss << v[i] << (i == iniciador ? "> " : " ");

    oss << "]";

    cout << oss.str() << endl;
}


retirando os elementos que morrem e diminuindo o tamanho do vetor.
reposicione os elementos “puxando” todos os que estiverem à frente
//faça a funcao matar que remove o elemento do vetor
//perceba que TUDO após pos, vai diminuir em 1
int elementos[size];
matar(elementos, size, pos);
size -= 1;
pos = pos % size; //se ele era o último agora é o zero

void josephus2(vector<int> &v, size_t &iniciador)
{
    while (v.size() >= 1)
    {
        if (iniciador == v.size())
            iniciador = 0;

        printVector2(v, iniciador);

        iniciador = (iniciador + 1) % v.size();

        v.erase(v.begin() + iniciador);
    }
}
*/
int main()
{
    size_t quantJogs, iniciador;
    cin >> quantJogs >> iniciador;

    vector<int> fila(quantJogs);
    prencherVector(fila);

    josephus1(fila, --iniciador);

    // josephus2(fila, --iniciador);

    return 0;
}