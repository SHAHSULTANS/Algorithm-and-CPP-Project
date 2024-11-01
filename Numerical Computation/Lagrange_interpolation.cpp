#include<bits/stdc++.h>
using namespace std;
 
struct Data
{
    double x, y;
};
 
double interpolate(Data f[], double xi, int n)
{
    double result = 0;
 
    for (int i=0; i<n; i++)
    {
        double term = f[i].y;
        for (int j=0;j<n;j++)
        {
            if (j!=i)
                term = term*(xi - f[j].x)/double(f[i].x - f[j].x);
        }

        result += term;
    }
 
    return result;
}
 

int main()
{
 
    Data f[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        double a;
        cin>>a;
        f[i].x=a;
        cin>>a;
        f[i].y=a;
    }
    cout<<"Enter value: ";
    double val;
    cin>>val;
    cout << "Value of f(3) is : " << interpolate(f, val, n);
 
    return 0;
}