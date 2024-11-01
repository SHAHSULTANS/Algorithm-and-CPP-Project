#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter number of people take service: ";
    int n,t=0,t2=0 ;
    cin>>n;
    vector<pair<int,int>>v;
    queue<int>center1,center2;
    cout<<"enter time  && service time take each person: "<<endl;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());

    center1.push(1);
    t=t+v[0].first+v[0].second-1;
    center2.push(2);
    t2=t2+v[1].first+v[1].second-1;

    for(int i=2;i<n;i++)
    {
        if(t<=t2)
        {
            t=t+v[i].second;
            center1.push(i+1);
        }
        else
        {
            t2=v[i].second;
            center2.push(i+1);
        }
    }
    cout<<"person who take service from first center: ";
    while(!center1.empty()){
        cout<<center1.front()<<" ";
        center1.pop();
    }
    cout<<endl<<endl;
    cout<<"person who take service from second center: ";
    while(!center2.empty()){
        cout<<center2.front()<<" ";
        center2.pop();
    }
    cout<<endl;
}