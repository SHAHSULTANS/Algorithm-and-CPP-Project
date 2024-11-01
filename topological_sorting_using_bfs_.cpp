#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int>*adj;
    public: 
    graph(int v);
    void addedge(int u,int v);
    void topological();

};
graph::graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}
void graph::addedge(int u,int v)
{
    adj[u].push_back(v);
}
void graph::topological()
{
    vector<int>indeg(v,0);
    for(int u=0;u<v;u++)
    {
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            indeg[*it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    int ctn=0;
    vector<int>topo;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(--indeg[*it]==0)
            {
                q.push(*it);
            }
            ctn++;
        }
    }
    if(ctn!=v)
    {
        cout<<"this is DAG"<<endl;
        return;
    }
    for(int i=0;i<topo.size();i++)
    {
        cout<<topo[i]<<" ";

    }
    cout<<endl;

}
int main()
{
    cout<<"enter total number of edge: ";
    int edge;
    cin>>edge;
    graph g(edge);
    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        g.addedge(a,b);

    }
    g.topological();

}