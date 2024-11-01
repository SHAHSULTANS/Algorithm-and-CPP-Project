// BFS using queue

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, i, j, ans = 0;
        cin >> n;
        long long ar[n];
        map<long long, long long> mp;
        for (i = 0; i < n; i++)
        {
            cin >> ar[i];
            mp[ar[i]]++;
        }
        long long q;
        cin >> q;
        while (q--)
        {
            long long x, y;
            cin >> x >> y;
            long long h = x * x - 4 * y;
            if (h < 0)
            {
                cout << 0<<" ";
                continue;
            }
            long long check=sqrt(h);
            if(check*check!=h)
            {
                cout<<0<<" ";continue;
            }
            long long a=(x+check)/2;long long b=(x-a);
            if(a!=b)
            {
                cout<<mp[a]*mp[b]<<" ";
            }
            else
            {
                long long c=mp[a];
                cout<<(c*(c-1))/2<<" ";
            }

        }
        cout<<endl;
    }
}