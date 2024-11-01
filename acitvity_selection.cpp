#include<bits/stdc++.h>
using namespace std;
bool com(pair<int,int>&a,pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    cout<<"Enter total number of confereence: ";
    int n;
    cin>>n;
    vector<pair<int,int> >v;
    cout<<"enter start & finish time: "<<endl;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
	    sort(v.begin(),v.end(),com);

    cout<<"\nacitviites are selected: "<<endl;
    int i=0;
    cout<<v[i].first<<" "<<v[i].second<<endl;
    for(int j=1;j<n;j++)
    {
        if(v[j].first>=v[i].second)
        {
            cout<<v[j].first<<" "<<v[j].second<<endl;
            i=j;
        }
    }
}
