#include<bits/stdc++.h>
using namespace std;
vector<int>ans(1000,1);
int LIS(int ar[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ar[i]>ar[j] && ans[i]<ans[j]+1)
            {
                ans[i]=ans[j]+1;
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(ans[i],maxi);

    }
    return maxi;

}
void print(int ar[],int n,int m)
{
    vector<int>v;
    int i=n-1;
    while(ans[i]<m)
    {
        i--;
    } 
    v.push_back(ar[i]);
    int check=ar[i];
    for(int j=i;j>=0;j--)
    {
        if(ar[j]<check && ans[j]+1==m)
        {
            m=ans[j];check=ar[j];
            v.push_back(ar[j]);
        }
    }
    for(i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int ar[n],i;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int m=LIS(ar,n);
    cout<<"LIS: "<<m<<endl;
    print(ar,n,m);
}