#include <iostream>
#include <vector>

using namespace std;

string fresquin(string &texto)
{
    vector<char> vogais = {'a', 'e', 'i', 'o', 'u'};

    for (size_t i = 0; i < texto.size(); i++)
    {
        if (texto.at(i) == ' ')
            for (size_t j = 0; j < vogais.size(); j++)
                if (texto.at(i - 1) == vogais[j] && texto.at(i + 1) == vogais[j])
                {
                    texto.erase(i, 1);
                    texto.erase(i, 1);

                    if (i != 1)
                        i--;
                }
    }

    return texto;
}

int main()
{
    string texto;

    getline(cin, texto);

    cout << fresquin(texto) << endl;

    return 0;
}