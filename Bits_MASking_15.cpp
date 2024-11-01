#include<bits/stdc++.h>
using namespace std;

int A[]={8,5,2};
int main()
{
    //cout<<pow(2,15)<<endl;

    int n = 3;  
    for(int i=1;i<(1<<n);i++)
    {
        int x = i;
        int subsetsum = 0;
        for(int j=0;j<n;j++)
        {
            if( (x&(1<<j)))
                subsetsum+=A[j]; 
        }
        cout<<subsetsum<<endl;
    }

    return 0;
}
