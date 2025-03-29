#include <iostream>
#include <queue>

using namespace std;

void fazerJogo(queue<char> &resultados)
{
    int jogo1, jogo2;
    cin >> jogo1 >> jogo2;

    char time1 = resultados.front();
    resultados.pop();

    char time2 = resultados.front();
    resultados.pop();

    resultados.push(jogo1 > jogo2 ? time1 : time2);
}

int main()
{
    queue<char> jogos;

    for (size_t i = 0; i < 16; i++)
        jogos.push('A' + i);

    while (jogos.size() > 1)
        fazerJogo(jogos);

    cout << jogos.front() << endl;

    return 0;
}