#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
stack<int>st;
int used[100];
void dfs(int root)
{
    used[root]=1;
    for(int it:v[root])
    {
        if(used[it]==0)
        {
            dfs(it);
        }
    }
    cout<<root<<" ";
    //cout<<root<<" "

}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        //v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            dfs(i);
            cout<<endl;
        }
    }
}
