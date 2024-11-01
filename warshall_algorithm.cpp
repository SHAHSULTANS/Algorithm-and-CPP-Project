#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int ar[1000][1000];
void warshall(int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                ar[i][j] = min(ar[i][j], (ar[i][k] + ar[k][j]));
                // if (ar[i][j] > (ar[i][k] + ar[k][j]) && (ar[k][j] != MAX && ar[i][k] != MAX))
                //     ar[i][j] = ar[i][k] + ar[k][j];
            }
        }
    }
    cout << endl;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (ar[i][j] == MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << ar[i][j]<< " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    cout << "enter the number of node: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "enter weight for " << i << " " << j << " edge" << endl;
            cin >> ar[i][j];
            if (ar[i][j] == 0)
            {
                if (i != j)
                {
                    // ar[i][j]=0;
                    ar[i][j] = MAX;
                }
            }
        }
    }
    warshall(n);
    return 0;
}