#include<bits/stdc++.h>
using namespace std;
void stk()
{
    cout<<"stack implentation"<<endl;
    stack<int>st;
    st.push(11);
    st.push(12);
    st.push(13);
    cout<<"guess size 3 "<<st.size()<<endl;
    st.pop();
    cout<<"guess size 2 "<<st.size()<<endl<<endl;

}
void que()
{
    cout<<"queue implentation"<<endl;
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    cout<<"guess size 3 "<<q.size()<<endl;
    q.pop();
    cout<<"guess size 2 & found "<<q.size()<<endl<<endl;
}
void prque()
{
    cout<<"priority queue implentation"<<endl;
    priority_queue<int>pq;
    pq.push(14);
    pq.push(10);
    pq.push(12);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl<<endl;
}
void lst()
{
    cout<<"list implentation"<<endl;
    list<string>l;
    l.push_front("shanto");
    l.push_front("shah");
    l.push_back("sultan");
    cout<<"guess size 3: found: "<<l.size()<<endl<<endl;
}
void pairin()
{
    cout<<"pair implentation"<<endl;
    vector<pair<int,int>>p;
    p.push_back({1,4});
    p.push_back({2,8});
    cout<<"p[0].second: 4  && found "<<p[0].second<<endl<<endl;
}
void sett()
{
    cout<<"sett implentation"<<endl;
    set<int>s;
    s.insert(1);s.insert(1);
    s.insert(2);
    cout<<"guess size 2 and found : "<<s.size()<<endl<<endl;
}
void mapping()
{
    cout<<"mapping implentation"<<endl;
    map<int,int>mp;
    mp[1]++;
    mp[1]++;
    cout<<"here hasing m[1] ==2 and found Is : "<<mp[1]<<endl<<endl;
}
void vec()
{
    cout<<"vector implentation"<<endl;
    vector<int>v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    cout<<"guess size 3 && found "<<v.size();
    v.pop_back();
    cout<<"after pop size 2 && found "<<v.size()<<endl;
}
int main()
{
    stk();
    que();
    prque();
    pairin();
    sett();
    mapping();
    vec();
}