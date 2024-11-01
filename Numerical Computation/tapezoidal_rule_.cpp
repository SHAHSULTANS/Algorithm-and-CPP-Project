#include <bits/stdc++.h>
using namespace std;

/* Define function here */
float f(float a)
{
    //return (exp(a));
    return(a*a*a+1);
}

int main()
{
    float lower, upper, integration = 0.0, h, k;
    int i, n;
    printf("Enter lower limit of integration: ");
    cin >> lower;
    printf("Enter upper limit of integration: ");
    cin >> upper;
    printf("Enter number of sub intervals: ");
    cin >> n;

    h = (upper - lower) / n;

    integration = f(lower) + f(upper);
    for (i = 1; i <= n - 1; i++)
    {
        k = lower + i * h;
        integration = integration + 2 * f(k);
    }
    integration = integration * (h / 2);
    printf("\nRequired value of integration is: %.3f", integration);
    return 0;
}
/*
-1 1 4
*/