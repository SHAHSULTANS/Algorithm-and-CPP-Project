
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[10];
vector<pair<int, pair<int, int>>> edgelist;
int dsu[20];
int findparent(int u)
{
    if (dsu[u] == u)
        return u;
        
    return dsu[u] = findparent(dsu[u]);
}
void PrintdsuTable()
{
    for (int i = 1; i <= 9; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 1; i <= 9; i++)
        cout << dsu[i] << " ";
    cout << endl;
}
int main()
{
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        char x, y;
        int w;

        cin >> x >> y >> w;
        int u = x - 'a' + 1;
        int v = y - 'a' + 1;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));

        if (u > v)
            swap(u, v);

        // pair<int, pair<int,int> >edg = make_pair(w, make_pair(u,v) );
        edgelist.push_back({w, {u, v}});
    }

    sort(edgelist.begin(), edgelist.end());

    for (int i = 1; i <= node; i++)
        dsu[i] = i;

    int totalcost = 0;

    for (int i = 0; i < edgelist.size(); i++)
    {
        int u, v, paru, parv;
        pair<int, int> e = edgelist[i].second;
        int edgeweight = edgelist[i].first;
        u = e.first;
        v = e.second;
        paru = findparent(u);
        parv = findparent(v);

        if (paru == parv)
        {
            cout << "Edge Between (" << char(u + 'a' - 1) << ", " 
            << char(v + 'a' - 1) << ") is ignored\n";
        }
        else
        {
            cout << "Edge(" << char(u + 'a' - 1) << ", " 
            << char(v + 'a' - 1) << "), --> " << edgeweight << endl;
            totalcost += edgeweight;
            if (paru > parv)
                swap(paru, parv);
            dsu[parv] = paru;

        }
    }

    cout << "Total Cost = " << totalcost << endl;
}

/*
9 14
g h 1
c i 2
f g 2
a b 4
c f 4
g i 6
c d 7
i h 7
a h 8
b c 8
d e 9
e f 10
b h 11
d f 14

*/

/*
a b c d e f g h i
1 2 3 4 5 6 7 8 9

9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7



5 9
 1 2 7
 1 4 2
 2 4 2
 4 2 3
 2 3 1
 4 3 8
 4 5 5
 3 5 4
 5 3 5

*/
