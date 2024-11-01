#include<bits/stdc++.h>
using namespace std;
int n,m;
int ar[1000];
int fun()
{
    if(n==1)
    {
        return 1;
    }
    if(n==3)
    {
        return 3;
    }
}
int main()
{
    cin>>n>>m;
    int i;
    ar[1]=1;
    ar[2]=1;
    ar[3]=2;
    for(i=4;i<=m;i++)
    {
        ar[i]=ar[i-3]+ar[i-1];

    }
    cout<<ar[m]<<endl;
}