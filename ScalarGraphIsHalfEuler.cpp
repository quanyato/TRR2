#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> vertexVisited;
vector<vector<int>> matrix;
vector<int> dfsArray;

void matrixPrintOut()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void clearVisitedArray()
{
    for (int i = 0; i <= vertexVisited.size(); i++)
    {
        vertexVisited[i] = 0;
    }
}

void getN()
{
    cin >> n;
    vertexVisited.resize(n + 1);
    matrix.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        matrix[i].resize(n + 1);
    }
}
void getMatrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
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
            if (matrix[vertex][index] == 1 && vertexVisited[index] == 0)
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

int numOfConnectedGraph()
{
    int countNumOfConnectedGraph = 0;
    for (int vertex = 1; vertex <= n; vertex++)

    {
        if (vertexVisited[vertex] == 0)

        {
            countNumOfConnectedGraph++;
            startDfs(vertex);
        }
    }
    return countNumOfConnectedGraph;
}

int soDinhBacLe()
{
    int dem;
    for (int i = 1; i <= n; i++)
    {
        int bacCuaDinh = 0;
        for (int j = 1; j <= n; j++)
        {
            bacCuaDinh += matrix[i][j];
        }
        if (bacCuaDinh % 2 != 0)
        {
            dem++;
        }
    }
    return dem;
}

string nuaEuler()
{
    if (numOfConnectedGraph() == 1)

    {
        int dinhBacLe = soDinhBacLe();
        if (dinhBacLe == 0 || dinhBacLe == 2)
        {
            return "La do thi nua Euler";
        }
        else
        {
            return "Khong phai do thi nua Euler";
        }
    }
    else
    {
        return "Khong phai do thi nua Euler";
    }
}

int main()
{
    getN();
    getMatrix();
    cout << nuaEuler();
}