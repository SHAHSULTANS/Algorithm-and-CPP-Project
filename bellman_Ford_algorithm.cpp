
#include <bits/stdc++.h>
using namespace std;
int v, e, graph[100][3+4];
void BellmanFord(int src)
{
    int dis[v + 4];
    for (int i = 1; i <= v; i++)
        dis[i] = INT_MAX;

    dis[src] = 0;
    for(int i=1;i<=v-1;i++)
    {
        for (int j = 1; j <= e; j++)
        {
            if (dis[graph[j][1]] != INT_MAX && dis[graph[j][1]] + graph[j][3] < dis[graph[j][2]])
            {
                dis[graph[j][2]] =dis[graph[j][1]] + graph[j][3];
            }
        }
    }
    for (int i = 1; i <= e; i++)
    {
        int x = graph[i][1];
        int y = graph[i][2];
        int weight = graph[i][3];
        if (dis[x] != INT_MAX &&
            dis[x] + weight < dis[y])
            cout << "Graph contains negative weight cycle"
                 << endl;
        //return;
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 1; i <= v; i++)
        cout << i << "\t\t" << dis[i] << endl;
}
int main()
{
    cout << "Enter vertexs: ";
    cin >> v;
    cout << "Enter number of Eedge: ";
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> graph[i][j];
        }
    }
    BellmanFord(1);
    return 0;
}

/*
1 2 -1
1 3 4
2 3 3
2 3 2
2 5 2 
4 3 5
4 2 1
5 4 -3
*/
