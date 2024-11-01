#include<bits/stdc++.h>
using namespace std;
int ar[100004];
void WriteFile()
{
    freopen("Input.txt","w",stdout);

    int N =10;
    cout<<N<<endl;
    for(int i=0;i<N;i++)
    {
        int x = rand();
        cout<<x<<" ";
    }
    cout<<endl;

}

int br[100];
float QuickSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

   

    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Quick Sort is "<< float(total)/1000.0<<endl;
}

float MergekSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start

    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Quick Sort is "<< float(total)/1000.0<<endl;
}

float BubbleSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                swap(ar[j],ar[j+1]);

            }

        }
    }

    ///Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Bubble Sort is "<< float(total)/1000.0<<endl;
}
void selectionsort(int ar[],int N)
{
     float time = 0;
    clock_t start= clock();
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(ar[i]>ar[j])
            {
                swap(ar[i],ar[j]);
            }
        }
    }

     clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in selection Sort is "<< float(total)/1000.0<<endl;

}
void insertionsort(int ar[],int N)
{
    int i,key;
    float time = 0;
    clock_t start= clock();
    for(int j=1;j<N;j++)
    {
        key=ar[j];
        i=j-1;
        while(i>=0 && ar[i]>key)
        {
            ar[i+1]=ar[i];
            i--;
        }
        ar[i+1]=key;
    }
    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in insertion Sort is "<< float(total)/1000.0<<endl;
}
void display(int ar[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        cerr<<ar[i]<<" ";
    }
    cerr<<endl;
}
int main()
{
    WriteFile();
    freopen("Input.txt","r",stdin);

    freopen("output.txt","w",stdout);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&ar[i]);
    }
    cerr<<"before sort the array became: ";
    display(ar,N);
    cerr<<endl;
    cerr<<endl;
    insertionsort(ar,N);
    BubbleSort(ar,N);
    selectionsort(ar,N);
    cerr<<"\nafter sort the array become ";
    display(ar,N);

    //QuickSort(ar,N ); ///
    //MergeSort(ar,N );
    ///....


    return 0;

}