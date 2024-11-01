#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st;
    st.push(11);
    st.push(12);
    st.push(13);
    cout<<"guess size 3 "<<st.size()<<endl;
    st.pop();
    cout<<"guess size 2 "<<st.size()<<endl;
}