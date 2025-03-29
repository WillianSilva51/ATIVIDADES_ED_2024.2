#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision

using namespace std;

struct ALUNO
{
    float nota[3];
    float media = 0.0f;
};

/* Recebe um ALUNO passado por referência, e preenche o campo 'media' com a
 média das 3 notas do ALUNO. */
void calcula_media(ALUNO *a)
{
    for (float &notas : a->nota)
        a->media += notas;

    a->media /= 3;
}

int main()
{
    ALUNO a;

    for (float &notas : a.nota)
        cin >> notas;

    calcula_media(&a); // Chame a função 'calcula_media' passando o ALUNO 'a' por referência.

    cout << fixed << setprecision(1) << a.media;

    return 0;
}