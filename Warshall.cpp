#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000
int main()
{
    int n;
    cout << "enter number of node : ";
    cin >> n;
    ll ar[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 0)
            {
                ar[i][j] = MAX;
            }
            if (i == j)
            {
                ar[i][j] = 0;
            }
        }
    }
    cout << "Graph represented matrix : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] == MAX)
            {
                cout << "inf ";
            }
            else
            {
                cout << ar[i][j] << " ";
            }
        }
        cout << endl;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ar[i][j] = min(ar[i][k] + ar[k][j], ar[i][j]);
            }
        }
    }
    cout << "Shortest Path: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] == MAX)
                cout << "inf ";

            else
                cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}
/*
0 5 0 10
0 0 3 0
0 0 0 1
0 0 0 0
*/
