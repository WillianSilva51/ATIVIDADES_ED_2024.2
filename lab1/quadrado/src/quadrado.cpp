#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void scan(vector<vector<int>> &matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[i].size(); j++)
            cin >> matrix[i][j];
}

string magico(const vector<vector<int>> &matrix)
{
    int soma = accumulate(matrix[0].begin(), matrix[0].end(), 0);
    int diagonalP = 0, diagonalS = 0;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        int linha = 0, coluna = 0;

        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            linha += matrix[i][j];
            coluna += matrix[j][i];
        }

        if (linha != soma || coluna != soma)
            return "nao";

        diagonalP += matrix[i][i];
        diagonalS += matrix[i][matrix.size() - 1 - i];
    }

    if (diagonalP == soma && diagonalS == soma)
        return "sim";

    return "nao";
}

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));

    scan(matrix);

    cout << magico(matrix) << endl;

    return 0;
}