#include <bits/stdc++.h>
using namespace std;
vector<int> G[2][100];
int start[20], ftime[20];
int tim, n, e, ctn, c = 0;
map<string, int> mp;
string str[30];
vector<pair<int, int>> temp;
vector<int> componenets[10];
void dfs(int idx, int u)
{
    start[u] = ++tim;
    for (auto x : G[idx][u])
    {
        if (start[x] == 0)
        {
            dfs(idx, x);
        }
    }
    ftime[u] = ++tim;
    if (idx == 1)
    {
        componenets[c].push_back(u);
    }
}
int main()
{
    cin >> n >> e;
    int i, x, y;
    for (i = 0; i < e; i++)
    {
        string a, b;
        cin >> a >> b;
        if (mp[a] == 0)
        {
            mp[a] = ++ctn;
            str[ctn] = a;
        }
        x = mp[a];
        if (mp[b] == 0)
        {
            mp[b] = ++ctn; // y=ctn;
            str[ctn] = b;
        }
        y = mp[b];
        G[0][x].push_back(y);
        G[1][y].push_back(x);
    }
    for (i = 1; i <= n; i++)
    {
        if (start[i] == 0)
            dfs(0, i);
    }
    for (i = 1; i <= n; i++)
    {
        cout << str[i] << " th nod start time: " << start[i]
             << " & finish time: " << ftime[i] << endl;
        pair<int, int> p = make_pair(ftime[i], i);
        temp.push_back(p);
    }
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    memset(start, 0, sizeof start);
    memset(ftime, 0, sizeof ftime);
    tim = 0;
    for (i = 0; i < temp.size(); i++)
    {
        int x = temp[i].second;
        if (start[x] == 0)
        {
            c++;
            dfs(1, x);
        }
    }
    cout << "Total Number of componenets = " << c << endl;
    for (int i = 1; i <= c; i++)
    {
        cout << "Component " << i << " Has " << componenets[i].size() << " nodes and they are: ";
        for (int j = 0; j < componenets[i].size(); j++)
        {
            cout << str[componenets[i][j]] << " ";
        }
        cout << endl;
    }
}
/*
8 14
A C
B A
B D
C D
C E
C B
D F
E F
E G
F D
F H
G E
G H
H H
*/
