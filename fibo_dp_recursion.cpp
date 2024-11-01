#include<bits/stdc++.h>
using namespace std;
int fib(vector<int>&dp,int n)
{
    if(n<=0)
    {
        return n;
    } 
    if(dp[n]!=0)
    {
        return dp[n];
    }
    dp[n]=fib(dp,n-1)+fib(dp,n-2);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n,0);
    dp[1]=1;
    cout<<fib(dp,n-1)<<endl;

}