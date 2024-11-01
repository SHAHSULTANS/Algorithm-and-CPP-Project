#include <bits/stdc++.h>
using namespace std;
#define fast() (ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL))
#define ll long long int
// double A, B, c;
// double a,b,c,d;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = exgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
// void print(double x)
// {
//     cout<<a*x*x*x+b*x*x+c*x+d<<endl;
// }
// double fun(double x)
// {
//     return a*x*x*x+b*x*x+c*x;
// }
int main()
{
    // fast();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, l;
        cin >> n;
        double a, b;
        int ar[n], i, j, sum = 0;
        for (i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        sort(ar, ar + n);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                sum=ar[i]+ar[j];
                auto it=lower_bound(ar,ar+n,sum)-ar;
                //cout<<it<<endl;
                //break;
            }
            //break;
        }
    }
}