#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vertexVisited;
vector<vector<int>> matrix;
vector<int> bfsArray;
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

void startBfs(int startVertex)
{
    queue<int> bfsQueue;
    int vertex = startVertex;
    int index;
    bfsQueue.push(vertex);
    bfsArray.push_back(vertex);
    vertexVisited[vertex] = 1;
    while (!bfsQueue.empty())
    {
        vertex = bfsQueue.front();
        index = 1;
        while (index <= n)
        {
            if (matrix[vertex][index] == 1 && vertexVisited[index] == 0)
            {
                bfsArray.push_back(index);
                bfsQueue.push(index);
                vertexVisited[index] = 1;
                break;
            }
            index++;
        }
        if (index > n)
        {
            bfsQueue.pop();
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
            startBfs(vertex);
        }
    }
    return countNumOfConnectedGraph;
}

void wayFromAtoB(int vertexA, int vertexB)
{
    int foundTheWay = 0;
    startBfs(vertexA);
    for (int i = 0; i < bfsArray.size(); i++)
    {
        if (bfsArray[i] == vertexB)
        {
            foundTheWay = 1;
            break;
        }
    }
    if (foundTheWay)
    {
        int i = 0;
        cout << bfsArray[i];
        while (bfsArray[i] != vertexB)
        {
            i++;
            cout << " " << bfsArray[i];
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
    cout << "----- Ung dung cua thuat toan BFS -----" << endl;
    cout << "Su dung ma tran ke de duyet tim kiem BFS" << endl;
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
            bfsArray.clear();
            clearVisitedArray();
            break;

        case 3:
            cout << numOfConnectedGraph() << " thanh phan lien thong" << endl;
            bfsArray.clear();
            clearVisitedArray();
            break;

        case 4:
            int vertexA, vertexB;
            cout << "Nhap dinh dau: ";
            cin >> vertexA;
            cout << "Nhap dinh cuoi: ";
            cin >> vertexB;
            wayFromAtoB(vertexA, vertexB);
            bfsArray.clear();
            clearVisitedArray();
            break;

        default:
            break;
        }
    }
}