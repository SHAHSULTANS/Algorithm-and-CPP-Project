#include<bits/stdc++.h>
using namespace std;
#define N 100000
double fun(double x)
{
    return x*x-x-2;
}
void flsmethod(double a,double b)
{
    if(fun(a)*fun(b)>=0)
    {
        cout<<"You have not correct inverval vlue"<<endl;
        return ;
    }
    double c=a;
    for(int i=0;i<N;i++)
    {
        c=(a*fun(b)-b*fun(a))/(fun(b)-fun(a));
        if(fun(c)==0)
        {
            break;
        }
        else if(fun(c)*fun(a)<0)
        {
            b=c;
        }
        else
        {
            a=c;
        }
        //cout<<"root value between "<<a<<" "<<b<<endl;

    }
    cout<<endl;
    cout<<"the root value is : "<<c<<endl;

}
int main()
{
    cout<<"enter interval value for a and b: ";
    double a,b;
    cin>>a>>b;
    flsmethod(a,b);
}