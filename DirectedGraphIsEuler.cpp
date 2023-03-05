#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<vector<int>> scalarMatrix;
vector<vector<int>> directedMatrix;
vector<int> dfsArray;
vector<int> vertexVisited;

void init()
{
    dfsArray.clear();
    cin >> n;
    scalarMatrix.resize(n + 1);
    directedMatrix.resize(n + 1);
    vertexVisited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        directedMatrix[i].push_back(0);
        scalarMatrix[i].resize(n + 1);
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            directedMatrix[i].push_back(tmp);
        }
    }
}

void converseToScalarM()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
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

void startDfs(int startVertex)
{
    stack<int> dfsStack;
    int vertex = startVertex;
    int index;
    dfsStack.push(vertex);
    dfsArray.push_back(vertex);
    vertexVisited[vertex] = 1;
    while (!dfsStack.empty())
    {
        vertex = dfsStack.top();
        index = 1;
        while (index <= n)
        {
            if (scalarMatrix[vertex][index] == 1 && vertexVisited[index] == 0)
            {
                dfsArray.push_back(index);
                dfsStack.push(index);
                vertexVisited[index] = 1;
                break;
            }
            index++;
        }
        if (index > n)
        {
            dfsStack.pop();
        }
    }
}

bool graphIsInterconnect()
{
    if (dfsArray.size() == n)
    {
        return true;
    }
    return false;
}

bool isEulerGraph()
{
    converseToScalarM();
    startDfs(1);
    if (not graphIsInterconnect)
    {
        return false;
    }
    for (int i = 1; i <= n; i++)
    {
        int degIn = 0, degOut = 0;
        for (int j = 1; j <= n; j++)
        {
            degOut += directedMatrix[i][j];
            degIn += directedMatrix[j][i];
        }
        if (degIn != degOut)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    init();
    if (isEulerGraph())
    {
        cout << "La do thi Euler";
    }
    else
    {
        cout << "Khong phai do thi Euler";
    }
}