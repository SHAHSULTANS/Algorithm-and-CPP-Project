#include <bits/stdc++.h>
using namespace std;
vector<int> graph[20];
int stime[20];
int ftime[20];
int tim;
void dfs(int u)
{
    stime[u] = ++tim;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (stime[v] == 0)
            dfs(v);
    }
    ftime[u] = ++tim;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "NOw For " << i << "th node, start time = " << stime[i] 
        << " and finish time = " << ftime[i] << endl;
    }
}
/*
8 14
1 2
1 4
1 7
2 7
2 5
3 2
3 5
3 8
4 6
4 7
5 7
6 1
7 6
8 7
*/
