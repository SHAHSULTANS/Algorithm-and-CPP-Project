#include<bits/stdc++.h>
using namespace std;
double equtaion(double x)
{
    return x*x*x-x*x+2;
}
double derequation(double x)
{
    return 3*x*x-2*x; 
}
void newton_rapson(double x)
{
    double divide=equtaion(x)/derequation(x);
    int i=1;
    while(abs(divide)>=0.001)
    {
        divide=equtaion(x)/derequation(x);
        x=x-divide;
        cout<<equtaion(x)<<" "<<derequation(x)<<endl;
        cout<<"iteration no "<<i<<" and value: "<<x<<endl;
        i++;
        
        
    }
    cout<<"the root vlue of this equation is: "<<x<<endl;

}
int main()
{
    cout<<"Enter initial guess value: ";
    double value;
    cin>>value;
    newton_rapson(value);
    return 0;
}