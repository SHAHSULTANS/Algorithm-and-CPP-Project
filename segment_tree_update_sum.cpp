#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 10000
int val;
ll A[N], tree[4 * N + 5];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = (tree[2 * node] + tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int pos, int val)
{
    if (start ==end)
    {
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
        {
            update(2 * node, start, mid, pos, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, pos, val);
        }
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
    }
}
ll query(int node, int start, int end, int l, int r)
{
    if(l>r)
    {
        return 0;
    }
    if(l==start && r==end)
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    return (query(node*2,start,mid,l,min(r,mid)) +query(node*2+1,mid+1,end,max(l,mid+1),r));
    
}
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    build(1, 1, n);

    // for(int i=0;i<4*n;i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;

    while (m--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int pos, val;
            cin >> pos>>val;
            pos++;
            update(1, 1, n, pos, val);
        }
        else
        {
            
            int l,r;cin>>l>>r;
            l++;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}