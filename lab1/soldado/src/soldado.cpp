#include <iostream>
#include <vector>

using namespace std;

void scan(vector<vector<int>> &matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[i].size(); j++)
            cin >> matrix[i][j];
}

int posicao(vector<vector<int>> &matrix)
{
    int quant = 0;

    for (size_t j = 0; j < matrix[0].size(); j++)
        for (size_t i = 0; i < matrix.size() - 1; i++)
            if (matrix[i][j] > matrix[i + 1][j])
                quant++;

    return quant;
}

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));

    scan(matrix);

    cout << posicao(matrix) << endl;

    return 0;
}

/*
for (size_t i = 0; i < matrix.size(); i++)
    for (size_t j = matrix[i].size() - 1, k = 1; j > 0; j--, k--)
        if (matrix.at(j).at(i) > matrix.at(k).at(i))
            quant++;
*/