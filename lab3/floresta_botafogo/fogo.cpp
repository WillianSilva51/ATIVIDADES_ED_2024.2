#include "fogo.hpp"

void tocar_fogo(std::vector<std::string> &mat, int l, int c)
{
    int nl = mat.size();    // numero de linhas
    int nc = mat[0].size(); // numero de colunas

    if ((l < 0 || l >= nl) || (c < 0 || c >= nc))
        return;

    if (mat[l][c] != '#')
        return;

    mat[l][c] = 'o';

    tocar_fogo(mat, l + 1, c);

    tocar_fogo(mat, l - 1, c);

    tocar_fogo(mat, l, c + 1);

    tocar_fogo(mat, l, c - 1);

    // Terminar de escrever essa funcao ..... Terminada
}