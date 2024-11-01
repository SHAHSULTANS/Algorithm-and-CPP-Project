#include<iostream>
#include<stdio.h>
using namespace std;
long long int n,k,memo[55][1010],ar[55],coin[55];
long long int ways(int in,int ex)
{
    if(ex==0)return 1;
    if(in<0 || ex<0)return 0;
    if(memo[in][ex]!=-1)return memo[in][ex];
    long long int ctn=0;
    for(int i=0;i<=coin[in];i++)
    {
        ctn=ctn+ways(in-1,ex-i*ar[in]);
        ctn=ctn%100000007;

    }
    memo[n][k]=ctn;
    return ctn;

}
 int main()
{
    long long int t,c=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long long int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        for(long long int i=0;i<n;i++)
        {
            cin>>coin[i];
        }
        //memset(memo,-1,sizeof(memo));
        long long int cp=ways(n-1,k);

        cout<<"Case "<<c++<<": "<<cp<<endl;


    }
}