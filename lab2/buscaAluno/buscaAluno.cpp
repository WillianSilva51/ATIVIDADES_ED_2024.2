#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct ALUNO
{
    int matricula;
    string nome;
    double media;
};

void LerAluno(ALUNO &aluno)
{
    cin >> aluno.matricula;
    cin.ignore();

    getline(cin, aluno.nome);

    cin >> aluno.media;
    cin.ignore();
}

void BuscarAluno(vector<ALUNO> &alunos)
{
    int matricula;
    cin >> matricula;

    for (ALUNO &aluno : alunos)
    {
        if (aluno.matricula == matricula)
        {
            cout << aluno.nome << "\n"
                 << fixed << setprecision(1) << aluno.media << endl;
            return;
        }
    }

    cout << "Aluno nao cadastrado";
}

int main()
{
    vector<ALUNO> alunos([]()
                         { int tam; cin >> tam; return tam; }());

    for (ALUNO &aluno : alunos)
        LerAluno(aluno);

    BuscarAluno(alunos);

    return 0;
}