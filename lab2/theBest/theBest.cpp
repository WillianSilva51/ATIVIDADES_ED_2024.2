#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct ALUNO
{
    string nome;
    vector<double> notas = vector<double>(3);
    double media = 0.0f;

    void lerAluno()
    {
        cin.ignore();
        getline(cin, nome);

        for (double &nota : notas)
            cin >> nota;

        media = calcularMedia();
    }

    double calcularMedia()
    {
        for (double nota : notas)
            media += nota;

        return media / 3;
    }
};

void maiorNota(vector<ALUNO> &turma)
{
    sort(turma.begin(), turma.end(), [](ALUNO &a, ALUNO &b)
         { return a.media > b.media; });

    for (size_t i = 0; i < turma.size(); i++)
    {
        cout << i << ": " << turma[i].nome << "\n"
             << fixed << setprecision(2) << "   Media: " << turma[i].media << "\n"
             << "   N1: " << turma[i].notas[0] << ", N2: " << turma[i].notas[1] << ", N3: " << turma[i].notas[2] << endl;
    }
}

int main()
{
    vector<ALUNO> alunos([]()
                         { int tam; cin >> tam; return tam; }());

    for (ALUNO &aluno : alunos)
        aluno.lerAluno();

    maiorNota(alunos);

    return 0;
}