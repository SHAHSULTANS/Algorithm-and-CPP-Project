#include<bits/stdc++.h>
using namespace std;
int ar[100];
void merging(int ar[],int l,int mid,int r)
{
    int one=mid-l+1;
    int two=r-mid;
    int *larr=new int[one];
    int *rarr=new int[two];
    int i;
    for(i=0;i<one;i++)
    {
        larr[i]=ar[l+i];
    }
    for(i=0;i<two;i++)
    { 
        rarr[i]=ar[mid+1+i];
    }
    int in1=0,in2=0,m=l;
    while(in1<one && in2<two)
    {
        if(larr[in1]<=rarr[in2])
        {
            ar[m]=larr[in1];
            in1++;
        }
        else
        {
            ar[m]=rarr[in2];
            in2++;
        }
        m++;
    }
    while(in1<one)
    {
        ar[m]=larr[in1];
        in1++;m++;
    }
    while(in2<two)
    {
        ar[m]=rarr[in2];
        in2++;m++;
    }
    delete[] larr;
    delete[] rarr;
    

}




void mergesort(int ar[],int const begin,int const last)
{
    if(begin>=last)
    {
        return;
    }
    int mid=begin+(last-begin)/2;
    mergesort(ar,begin,mid);
    mergesort(ar,mid+1,last);
    merging(ar,begin,mid,last);

}
int main()
{
    int i,n;
    cin>>n;
    //int ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    mergesort(ar,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

}