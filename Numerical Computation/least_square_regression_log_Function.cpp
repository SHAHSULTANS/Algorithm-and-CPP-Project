#include <bits/stdc++.h>
using namespace std;
void leastsqreg(vector<double> &dataX, vector<double> &dataY, double &m, double &b)
{
    int n = dataX.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += log(dataX[i]);
        sumY += log(dataY[i]);
        sumXY += log(dataX[i]) * log(dataY[i]);
        sumX2 += log(dataX[i]) * log(dataX[i]);
    }

    m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double lnb = (sumY - m * sumX) / (n * 1.0);
    b = exp(lnb);
}

int main()
{
    int n;
    cout << "Enter the Value of  N: ";
    cin >> n;
    vector<double> dataX(n);
    vector<double> dataY(n);
    cout << "Enter the value of X one by one : ";
    for (int i = 0; i < n; i++)
    {
        cin >> dataX[i];
    }
    cout << "Enter the value of Y one by one : ";
    for (int i = 0; i < n; i++)
    {
        cin >> dataY[i];
    }
    double slope_M, intercept_C;
    leastsqreg(dataX, dataY, slope_M, intercept_C);

    cout << "\nEquation of the line: y = " << intercept_C << "x ^" << slope_M << endl;

    return 0;
}
/*

Y=ax^b


 5
1 2 3 4 5
0.5 2 4.8 8 12.5

Equation of the line: y = 0.503769x ^2.00564
*/