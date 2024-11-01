
#include<bits/stdc++.h>
using namespace std;

double calculateB(int x[], int y[], int n)
{
	
	int sx = accumulate(x, x + n, 0);

	
	int sy = accumulate(y, y + n, 0);

	int sxsy = 0;


	int sx2 = 0;
	for(int i = 0; i < n; i++)
	{
		sxsy += x[i] * y[i];
		sx2 += x[i] * x[i];
	}
	double b = (double)(n * sxsy - sx * sy) /
					(n * sx2 - sx * sx);

	return b;
}

void leastRegLine( int X[], int Y[], int n)
{

	double b = calculateB(X, Y, n);

	float meanX = (float)accumulate(X, X + n, 0) / n;
	float meanY = accumulate(Y, Y + n, 0);
    meanY=float(meanY)/n;

	double a = meanY - b * meanX;

	
	cout << ("Regression line:") << endl;
	cout << ("Y = ");
	printf("%.3f + ", a);
	printf("%.3f *X", b);
}


int main()
{
	
	int X[100];
    int Y[100];
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin>>X[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>Y[i];
    }
	
	leastRegLine(X, Y, n);
}
/*
5
1 2 3 4 5   
3 4 5 6 8 
*/
