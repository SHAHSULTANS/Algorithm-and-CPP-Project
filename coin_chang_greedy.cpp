#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    cout<<"given number of coin: ";
    cin>>n;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
	cout<<"enter exchange coin: ";
    int ex;cin>>ex;
    sort(v.begin(),v.end());
    //sort(v.begin().v.end());
    int c=0;
    for(i=v.size()-1;i>=0;i--)
    {
        while(ex>=v[i])
        {
            c++;
            cout<<v[i]<<" ";
            ex=ex-v[i];

        }
    }
    cout<<"\n minimum coin need: "<<c<<endl;
    cout<<endl;
    return 0;
}

