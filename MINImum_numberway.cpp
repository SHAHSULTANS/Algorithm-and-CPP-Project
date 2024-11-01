#include<bits/stdc++.h>
using namespace std;
int ar[100000];
int fun(int n)
{
    if(ar[n]!=0)return ar[n];
    if(n==1)
    {
        return 0; 
    }  
    int s=INT_MAX;
    if(n%2==0)
    {
        s=min(s,fun(n/2)+1);
    }
    if(n%3==0)
    {
        s=min(s,fun(n/3)+1);
    }
    s=min(s,fun(n-1)+1);
    ar[n]=s;
    return ar[n];
}
int main()
{
    int n,ctn=0,i;
    cin>>n;
    //cout<<fun(n)<<endl;
    ar[1]=0;
    for(i=2;i<=n;i++)
    {
        int s=INT_MAX;
        if(i%2==0)
        {
            s=min(s,ar[i/2]+1);
        }
        if(i%3==0)
        { 
            s=min(s,ar[i/3]+1);
        }
        s=min(s,ar[i-1]+1);
        ar[i]=s;

        
    }
    for(i=1;i<=n;i++)
    {
        cout<<ar[i]<<" ";
    }
    // while(n)
    // {
    //     if(n%3==0)
    //     {
    //         ctn++;
    //         n=n/3;
    //     }
    //     else if(n%2==0)
    //     {
    //         n=n/2;
    //         ctn++;
    //     }
    //     else
    //     {
    //         ctn++;
    //         n--;
    //     }
    //     if(n==1)
    //     {
    //         break;
    //     }
    // }
   ///cout<<ctn<<endl;
}