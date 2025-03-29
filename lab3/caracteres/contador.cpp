#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(const string &str, const int &n, const char &c)
{
    if (n < 0)
        return 0;

    return (str[n] == c) + contaCaracteres(str, n - 1, c);
}

int main()
{
    string frase;

    getline(cin, frase);

    char letra;
    cin >> letra;

    cout << contaCaracteres(frase, frase.size(), letra) << endl;

    return 0;
}