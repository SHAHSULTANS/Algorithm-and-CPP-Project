#include <bits/stdc++.h>
using namespace std;
int w[] = {0, 2, 1, 3, 2};
int value[] = {0, 12, 10, 20, 15};
int memo[1000][1000];
vector<int> v;
int f(int i, int Kcap)
{
    if (i <= 0 || Kcap <= 0)
    {
        return 0;
    }
    if (Kcap - w[i] < 0)
    {
        return 0;
    }
    if (memo[i][Kcap] == -1)
    {
        int Nibo = f(i - 1, Kcap - w[i]) + value[i];

        int NiboNa = f(i - 1, Kcap);
        memo[i][Kcap] = max(Nibo, NiboNa);
    }
    return memo[i][Kcap];
}
void PathPrint(int n, int i, int Kcap)
{

    if (i <= 0 || Kcap <= 0 || n == 0)
    {

        return;
    }
    if (n - value[i] == memo[i - 1][Kcap - w[i]])
    {
        v.push_back(i);
        PathPrint(n - value[i], i - 1, Kcap - w[i]);
    }
    else
    {
        PathPrint(n, i - 1, Kcap);
    }
}

int main()
{

    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            memo[i][j] = -1;
        }
    }
    int n = f(4, 5);
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    PathPrint(n, 4, 5);
    cout << "The max profit " << n << endl;
    cout << "The items are taken : ";
    for (auto u : v)
    {
        cout << u << " ";
    }
    return 0;
}