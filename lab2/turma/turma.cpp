#include <iostream> // cout, cin, fixed
#include <iomanip>  // setprecision
#include <vector>   // vector

using namespace std;

struct ALUNO
{
    float nota[3];
    float media;
};

// Recebe um ALUNO passado por referência, e preenche o campo 'media' com a
// média das 3 notas do ALUNO.
void calcula_media(ALUNO *a)
{
    for (float &notas : a->nota)
        a->media += notas;

    a->media /= 3;
}

// Recebe vetor de alunos ('turma') e número de alunos ('n'), e chama a função
// 'calcula_media' (da questão anterior) para cada ALUNO do vetor.
// Ou seja, preenche o campo 'media' de cada ALUNO com a média das 3 notas do ALUNO.
void calcula_media_turma(vector<ALUNO> &turma)
{
    for (ALUNO &aluno : turma)
        calcula_media(&aluno);
}

int main()
{
    vector<ALUNO> turma([]()
                        { int tam; cin >> tam; return tam; }());

    for (ALUNO &aluno : turma)
        for (float &notinhas : aluno.nota)
            cin >> notinhas;

    calcula_media_turma(turma); // Chame a função 'calcula_media_turma' passando o vetor de alunos 'turma'.

    for (ALUNO &alunos : turma)
        cout << fixed << setprecision(1) << alunos.media << " ";

    cout << endl;

    return 0;
}