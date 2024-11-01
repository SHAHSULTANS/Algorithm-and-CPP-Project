#include<bits/stdc++.h>
using namespace std;
vector<int>g[10];
/*
8 9
1 2
1 5
2 6
3 4
3 6
3 7
4 8
6 7
7 8

*/
int dis[10], discover[10];
queue<int>q;
    int n,e;
void bfs(int src)
{
    for(int i=1;i<=n;i++)dis[i]=1000;
    dis[src]=0;
    discover[src]=1;

    q.push(src);

    while(!q.empty())
    {
        // --> queue er front element ta niye asho.
        // --> queue theke pop koro.
        int x=q.front();q.pop();

        // Dhoro, x queue er front a chilo.
        for(auto it=g[x].begin();it!=g[x].end();it++)
        {
            // let, v is the adjacent of x.
            // jodi, v already discovered na hoy,
            //     --> dis(v) update koro.
            //     --> insert v into the queue.
            if(discover[*it]==0)
            {
                dis[*it]=dis[x]+1;
                discover[*it]=1;
                q.push(*it);
            }
        }
    }

}
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(2);
    cout<<"distan from source 2 of each vertex: "<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<" 2 "<<i<<" cost->"<<dis[i]<<" "<<endl;
    }
    return 0;
}
