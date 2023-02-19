#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vertexVisited;
vector<vector<int>> matrix;
vector<int> dfsArray;
string filePath = "C:\\Users\\YATO\\OneDrive - ptit.edu.vn\\Documents\\Dev\\PTIT\\TRR2\\matrix.in";

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

void getN_fromFile(string filePath)
{
    fstream inputFile;
    inputFile.open(filePath, ios::in);
    inputFile >> n;
    inputFile.close();
    vertexVisited.resize(n + 1);
    matrix.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        matrix[i].resize(n + 1);
    }
}
void getMatrix_fromFile(string filePath)
{
    int temp;
    fstream inputFile;
    inputFile.open(filePath, ios::in);
    inputFile >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();
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

void wayFromAtoB(int vertexA, int vertexB)
{
    int foundTheWay = 0;
    startDfs(vertexA);
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

string theGraphisInterconnected()
{
    if (numOfConnectedGraph() == 1)
    {
        return "Do thi lien thong";
    }
    else
    {
        return "Do thi khong lien thong";
    }
}

int main()
{
    system("cls");
    int choice;
    int exitProgram = 0;
    getN_fromFile(filePath);
    getMatrix_fromFile(filePath);
    cout << "----- Ung dung cua thuat toan DFS -----" << endl;
    cout << "Su dung ma tran ke de duyet tim kiem DFS" << endl;
    cout << "Matrix file path: " << filePath << endl
         << endl;
    cout << "1. In ra ma tran ke INPUT." << endl;
    cout << "2. Xet tinh lien thong." << endl;
    cout << "3. Dem so thanh phan lien thong." << endl;
    cout << "4. Tim duong di tu dinh A den dinh B." << endl;
    cout << "0. Thoat" << endl;
    while (not exitProgram)
    {
        cout << "-- Nhap lua chon cua ban (Number): ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exitProgram = 1;
            break;

        case 1:
            matrixPrintOut();
            break;

        case 2:
            cout << theGraphisInterconnected() << endl;
            dfsArray.clear();
            clearVisitedArray();
            break;

        case 3:
            cout << numOfConnectedGraph() << " thanh phan lien thong" << endl;
            dfsArray.clear();
            clearVisitedArray();
            break;

        case 4:
            int vertexA, vertexB;
            cout << "Nhap dinh dau: ";
            cin >> vertexA;
            cout << "Nhap dinh cuoi: ";
            cin >> vertexB;
            wayFromAtoB(vertexA, vertexB);
            dfsArray.clear();
            clearVisitedArray();
            break;

        default:
            break;
        }
    }
}