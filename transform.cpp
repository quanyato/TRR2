#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int dau;
    int cuoi;
} edge;

void Trans_dscanh(int n, int a[10][10], string outPath)
{
    ofstream output(outPath);
    vector<edge> dscanh;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j])
            {
                dscanh.push_back({i + 1, j + 1});
            }
        }
    }

    for (int i = 0; i < dscanh.size(); i++)
    {
        output << dscanh[i].dau << " " << dscanh[i].cuoi << endl;
    }
    output.close();
}

void Trans_dske(int n, int a[10][10], string outPath)
{
    ofstream output(outPath);
    vector<int> dske[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
            {
                dske[i + 1].push_back(j + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        output << "Ke(" << i << ") = { ";
        for (int j = 0; j < dske[i].size(); j++)
        {
            output << dske[i][j] << ", ";
        }
        output << "}" << endl;
    }
    output.close();
}

int main()
{
    // lay du lieu
    ifstream input("C:\\Users\\YATO\\OneDrive - ptit.edu.vn\\Documents\\Dev\\TRR2\\MtrKeVh.in");
    int a[10][10], n;
    input >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> a[i][j];
        }
    }
    input.close();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Chuyen doi
    string outPath = "C:\\Users\\YATO\\OneDrive - ptit.edu.vn\\Documents\\Dev\\TRR2\\DsCanh.out";
    Trans_dscanh(n, a, outPath);
    outPath = "C:\\Users\\YATO\\OneDrive - ptit.edu.vn\\Documents\\Dev\\TRR2\\DsKe.out";
    Trans_dske(n, a, outPath);
}