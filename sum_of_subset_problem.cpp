#include <bits/stdc++.h>
using namespace std;
int memo[1000][1000];
int ar[1000];
void subset_of(int n, int sum, vector<int> v)
{
    if (sum == 0)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    if (n <= 0)
    {
        return;
    }
    //nibona er  operation.
    subset_of(n - 1, sum, v);
    //nibo er operation.
    v.push_back(ar[n - 1]);
    subset_of(n - 1, sum - ar[n - 1], v);
}
int main()
{
    vector<int> v;
    int n;
    cout<<"Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << "Enter value of sum do you want ";
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            memo[i][j] = -1;
        }
    }
    subset_of(n, k, v);
}