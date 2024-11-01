#include <bits/stdc++.h>
using namespace std;
const int R =1, C = 10, I = 10;
int main()
{
    int i, j, k, ar[R][C][I];
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            for (k = 0; k < I; k++)
            {
                cin >> ar[i][j][k];
            }
        }
    }
    cout<<"before sorting shelf 1 is contain books: ";
    for(i=0;i<I;i++)
    {
        cout<<ar[0][0][i]<<" ";
    }
    cout<<endl<<endl;

    for (i = 0; i < I; i++)
    {
        if (ar[0][0][i] != 1){
        for (j = 0; j < R; j++){
        for (k = 0; k < C; k++){
        if (j == 0 && k == 0)
        {
         continue;
        }
        for (int f = 0; f < I; f++){
        if (ar[j][k][f] == 1)
        {
        swap(ar[0][0][i], ar[j][k][f]);
        }
        }
        }
        }
        }
    }
    cout<<"after sorting first shelf 1-1 books: ";
    for (i = 0; i < I; i++)
    {
        cout << ar[0][0][i] << " ";
    }
    cout<<endl;
}