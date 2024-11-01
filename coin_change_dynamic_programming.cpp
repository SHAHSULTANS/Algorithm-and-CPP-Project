#include<bits/stdc++.h>
using namespace std;
int memo[1000][1000];
int ar[1000];
int coinchange(int n,int sum)
{
    if(sum==0)
    {
        return 1;
    }
    if(sum<0)
    {
        return 0;
    }
    if(n<0)
    {
        return 0;
    }
    if(memo[n-1][sum]!=-1)
    {
        return memo[n-1][sum];
    }
    if(ar[n-1]>sum)
    {
        memo[n-1][sum]=coinchange(n-1,sum);
        return memo[n-1][sum];
    }
    else
    {
        //nibo or nibona er bitwise (OR) operation.
        memo[n-1][sum]=coinchange(n-1,sum)|coinchange(n-1,sum-ar[n-1]);
        return memo[n-1][sum];
    }
}
int main()
{
    int n;
    cout<<"enter number nth of coin: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter value of exchange coin ";
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            memo[i][j]=-1;
        }
    }
    if(coinchange(n,k))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
}