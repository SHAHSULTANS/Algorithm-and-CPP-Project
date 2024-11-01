#include<bits/stdc++.h>
using namespace std;
int lis(int ar[],int n)
{
    int *lis,i,j,maxi=0;
    lis=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        lis[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ar[i]>ar[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        maxi=max(maxi,lis[i]);
    }
    free(lis);
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<lis(ar,n)<<endl;

}