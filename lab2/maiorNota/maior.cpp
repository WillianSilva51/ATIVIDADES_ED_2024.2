#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct ALUNO
{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

void LerAluno(ALUNO &aluno)
{
    getline(cin, aluno.nome);

    cin >> aluno.matricula;
    cin.ignore();

    getline(cin, aluno.disciplina);

    cin >> aluno.nota;
    cin.ignore();
}

void MaiorNota(vector<ALUNO> &alunos)
{
    if (alunos[0].nota == alunos[1].nota)
        cout << alunos[0].nome << " e " << alunos[1].nome << ", " << fixed << setprecision(1) << alunos[0].nota;

    else if (alunos[0].nota > alunos[1].nota)
        cout << alunos[0].nome << ", " << fixed << setprecision(1) << alunos[0].nota;

    else
        cout << alunos[1].nome << ", " << fixed << setprecision(1) << alunos[1].nota;
}

int main()
{
    vector<ALUNO> alunos(2);

    for (ALUNO &aluno : alunos)
        LerAluno(aluno);

    MaiorNota(alunos);

    return 0;
}