#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<int> dfsArray;
string filePath = "C:\\Users\\YATO\\OneDrive - ptit.edu.vn\\Documents\\Dev\\PTIT\\TRR2\\input002.in";

void clearVisitedArray(int visitedArray[])
{
    for (int i = 0; i <= n; i++)
    {
        visitedArray[i] = 0;
    }
}

void getN_fromFile(string filePath)
{
    fstream inputFile;
    inputFile.open(filePath, ios::in);
    inputFile >> n;
    inputFile.close();
}
void getMatrix_fromFile(string filePath)
{
    int temp;
    fstream inputFile;
    inputFile.open(filePath, ios::in);
    inputFile >> n;
    matrix.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        matrix[i].resize(n + 1);
        for (int j = 1; j <= n; j++)
        {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();
}

void startDfs(int startVertex, int visited[])
{
    stack<int> dfsStack;
    int vertex = startVertex;
    int index;
    dfsStack.push(vertex);
    dfsArray.push_back(vertex);
    visited[vertex] = 1;
    while (!dfsStack.empty())
    {
        vertex = dfsStack.top();
        index = 1;
        while (index <= n)
        {
            if (matrix[vertex][index] == 1 && visited[index] == 0)
            {
                dfsArray.push_back(index);
                dfsStack.push(index);
                visited[index] = 1;
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

int numOfConnectedGraph(int visited[])
{
    int countNumOfConnectedGraph = 0;
    for (int vertex = 1; vertex <= n; vertex++)
    {
        if (visited[vertex] == 0)
        {
            countNumOfConnectedGraph++;
            startDfs(vertex, visited);
        }
    }
    return countNumOfConnectedGraph;
}

void wayFromAtoB(int vertexA, int vertexB, int visited[])
{
    int foundTheWay = 0;
    startDfs(vertexA, visited);
    for (int i = 0; i < dfsArray.size(); i++)
    {
        if (dfsArray[i] == vertexB)
        {
            foundTheWay = 1;
            break;
        }
    }
    if (foundTheWay)
    {
        int i = 0;
        cout << dfsArray[i];
        while (dfsArray[i] != vertexB)
        {
            i++;
            cout << " " << dfsArray[i];
        }
        cout << endl;
    }
    else
    {
        cout << "There no way from " << vertexA << " to " << vertexB << endl;
    }
}

int main()
{
    getN_fromFile(filePath);
    getMatrix_fromFile(filePath);
    int visited[n + 1] = {};
    wayFromAtoB(1, 3, visited);
}