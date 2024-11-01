#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    double r1 = (double)a.first / (double)a.second;
    double r2 = (double)b.first / (double)b.second;
    return r1 > r2;
}

int main()
{
    cout << "enter weight of knapsack: ";
    int weight;
    cin >> weight;
    cout << "enter total number of product: ";
    int n, i;
    cin >> n;
    vector<pair<int, int>> v;
    cout << "enter first value profit then enter  weight: " << endl;
    for (i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int current = 0;
    double profit = 0;
    for (i = 0; i < n; i++)
    {
        if (current + v[i].second <= weight)
        {
            current += v[i].second;
            profit += v[i].first;
        }
        else
        {
            int remain = weight - current;
            double total = v[i].first * ((double)remain / (double)v[i].second);
            profit += total;
            break;
        }
    }
    cout << "maximum profit: " << profit << endl;
    return 0;
}
