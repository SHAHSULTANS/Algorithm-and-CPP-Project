#include <bits/stdc++.h>
using namespace std;

vector<int> G[20];
int stime[20];
int ftime[20];
int tim;
vector<int> ans;
void dfs(int u)
{
    stime[u] = ++tim;
    for (auto v : G[u])
    {
        if (stime[v] == 0)
            dfs(v);
    }
    ftime[u] = ++tim;

    ans.push_back(u);
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        if (stime[i] == 0)
            dfs(i);

    for (int i = 1; i <= n; i++)
    {
        cout << "For " << i << "th node, start time = " << stime[i] << 
        " and finish time = " << ftime[i] << endl;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i< ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
/*
9 9
1 3
1 4
2 4
3 4
3 5
5 9
6 5
6 8
8 9

*/
