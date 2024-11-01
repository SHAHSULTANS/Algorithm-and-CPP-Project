#include<bits/stdc++.h>
using namespace std;
double l,up;
    int n;
double fun(double x)
{
    return(x*x*x+1);
}
double simpson()
{
    double h,res=0,oddsum=0,evensum=0,lim;
    h=(up-l)/n;
    res=(fun(l)+fun(up));
    lim=n/2;
    for(int i=1;i<=lim;i++)
    {
        oddsum=oddsum+fun(l+(2*i-1)*h);
    }
    oddsum=oddsum*4;
    for(int i=1;i<lim;i++)
    {
        evensum=evensum+fun(l+(2*i)*h);
    }
    evensum=evensum*2;
    res=res+oddsum+evensum;
    res=res*(h/3);
    cout<<"the result is: "<<res<<endl;

}
int main()
{
    cout<<"enter low and upper bound: ";
    cin>>l>>up;
    cout<<"Enter interval: ";
    cin>>n;
    simpson();
    return 0;

}
/*
0 1.57
6
*/