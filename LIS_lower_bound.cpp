#include<bits/stdc++.h>
using namespace std;
void lis(vector<int>&v,int n)
{
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(ans.begin(),ans.end(),v[i]);
        if(it==ans.end())
        {
            ans.push_back(v[i]);
        }
        else
        {
            *it=v[i];
        }
    }
    cout<<"LIS: "<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    lis(v,n);

}