#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
ll findinverse(ll var_Mn[],ll modvalue[],ll i)
{
    ll x=1;
    while(true)
    {
        ll rem=(var_Mn[i]*x)%modvalue[i];
        if(rem==1)
        {
            return x;
            break;
        }
        x++;
    }
}
int main()
{
    ll n;
    cout<<"Enter the number of equation : ";
    cin>>n;
    ll ar[n],modvalue[n],var_Mn[n],modinverse[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the value of a"<<i+1<<" = ";
        cin>>ar[i];
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the value of m"<<i+1<<" = ";
        cin>>modvalue[i];
    }
    ll BMod=1;
    for(int i=0; i<n; i++)
    {
        BMod*=modvalue[i];
    }
    for(int i=0; i<n; i++)
    {
        var_Mn[i]=(BMod/modvalue[i]);
    }
     for(int i=0;i<n;i++)
    {
        modinverse[i]=findinverse(var_Mn,modvalue,i);
    }
    ll X=0;
    for(int i=0;i<n;i++)
    {
        X+=ar[i]*var_Mn[i]*modinverse[i];
    }
    cout<<"\nValue of X = ";
    cout<<X%BMod<<endl;
}
/*
Enter the number of equation : 3
Enter the value of a1 = 2
Enter the value of a2 = 3
Enter the value of a3 = 2

Enter the value of m1 = 3
Enter the value of m2 = 5
Enter the value of m3 = 7

Value of X = 23

*/
