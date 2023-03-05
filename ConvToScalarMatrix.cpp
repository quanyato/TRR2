#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> scalarMatrix;
vector<vector<int>> directedMatrix;

void init()
{
    cin >> n;
    scalarMatrix.resize(n);
    directedMatrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        scalarMatrix[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            directedMatrix[i].push_back(tmp);
        }
    }
}

void converseToScalarM()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (directedMatrix[i][j] == 1 || directedMatrix[j][i] == 1)
            {
                scalarMatrix[i][j] = 1;
                scalarMatrix[j][i] = 1;
            }
            else
            {
                scalarMatrix[i][j] = 0;
                scalarMatrix[j][i] = 0;
            }
        }
    }
}

int main()
{
    init();
    converseToScalarM();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << scalarMatrix[i][j] << " ";
        }
        cout << endl;
    }
}