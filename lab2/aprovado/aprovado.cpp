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

string aprovado(ALUNO &alunos)
{
    if (alunos.nota >= 7)
        return alunos.nome + "aprovado(a) em " + alunos.disciplina;

    else
        return alunos.nome + "reprovado(a) em " + alunos.disciplina;
}

int main()
{
    ALUNO alunos;

    LerAluno(alunos);

    cout << aprovado(alunos) << endl;

    return 0;
}