#include<bits/stdc++.h>
using namespace std;
int ar[100];
void calsubsum(int n,int c,vector<int>&v)
{
    for(int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sum=sum+ar[j+c];
            }
            
        }
        v.push_back(sum);
    }

}
int main()
{
    vector<int>v1,v2;
    int n,ctn=0;
    cout<<"Enter N: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter sum value: ";
    int s;
    cin>>s;
    calsubsum(n/2,0,v1);
    calsubsum((n+1)/2,(n/2),v2);
    sort(v1.begin(),v1.end());
    int sz=v1.size();
    for(int i=0;i<v2.size();i++)
    {
        int search=0;
        if(v2[i]<=s)
        {
            search=s-v2[i];
            auto it=lower_bound(v1.begin(),v1.end(),search)-v1.begin();
            if(it==sz)
            {
                it--;
            }
            if(search==v1[it])
            {
                ctn++;
               // break;
            }

        }

    }
    cout<<"total type of subsetsum is : "<<ctn<<endl;
}