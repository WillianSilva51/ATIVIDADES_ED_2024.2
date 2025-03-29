#include <iostream>
#include <vector>

using namespace std;

struct PESSOA
{
    string nome;
    int idade;
    char sexo;

    PESSOA() : nome(""), idade(0), sexo(' ') {}

    void lerPessoa()
    {
        cin >> nome;
        cin.ignore();

        cin >> idade;
        cin.ignore();

        cin >> sexo;
    }
};

void maisvelha(vector<PESSOA> &pessoas)
{
    PESSOA maisvelha = pessoas[0];

    for (PESSOA &pessoa : pessoas)
        if (pessoa.idade > maisvelha.idade)
            maisvelha = pessoa;

    cout << maisvelha.nome << endl;
}

void temMulher(vector<PESSOA> &pessoas)
{
    vector<PESSOA> mulhers;

    for (PESSOA &pessoa : pessoas)
        if (pessoa.sexo == 'f')
            mulhers.push_back(pessoa);

    if (mulhers.empty())
    {
        cout << "nao tem mulher" << endl;
        return;
    }

    maisvelha(mulhers);
}

int main()
{
    vector<PESSOA> pessoas([]()
                           { int tam; cin >> tam; return tam; }());

    for (PESSOA &pessoa : pessoas)
        pessoa.lerPessoa();

    temMulher(pessoas);

    return 0;
}