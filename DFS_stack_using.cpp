#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
stack<int>st;
int used[100];
void dfs(int root)
{
    
    cout<<root<<" ";
    used[root]=1;
    for(int it:v[root])
    {
        if(used[it]==0)
        {
            dfs(it);
        }
    }

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
        v[b].push_back(a);
    }
    cout<<"Enter root: ";
    int root;
    cin>>root;
    dfs(root);
    cout<<endl;
}
