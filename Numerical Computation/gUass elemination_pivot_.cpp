#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100;

void partial_pivot(double A[MAXN][MAXN+1], int n) {
	for (int i = 0; i < n; i++) {
		int pivot_row = i;
		for (int j = i+1; j < n; j++) {
			if (abs(A[j][i]) > abs(A[pivot_row][i])) {
				pivot_row = j;
			}
		}
		if (pivot_row != i) {
			for (int j = i; j <= n; j++) {
				swap(A[i][j], A[pivot_row][j]);
			}
		}
		for (int j = i+1; j < n; j++) {
			double factor = A[j][i] / A[i][i];
			for (int k = i; k <= n; k++) {
				A[j][k] -= factor * A[i][k];
			}
		}
	}
}

void back_substitute(double A[MAXN][MAXN+1], int n, double x[MAXN]) {
	for (int i = n-1; i >= 0; i--) {
		double sum = 0;
		for (int j = i+1; j < n; j++) {
			sum += A[i][j] * x[j];
		}
		x[i] = (A[i][n] - sum) / A[i][i];
	}
}

int main() {
	int n = 3;
	double A[MAXN][MAXN+1] = {{3.0, 2.0,-4.0, 3.0},
							{2.0, 3.0, 3.0, 15.0},
							{5.0, -3, 1.0, 14.0}
							};
	double x[MAXN];
	
	partial_pivot(A, n);
	back_substitute(A, n, x);
	
	cout << "Solution for the system:\n";
	for (int i = 0; i < n; i++) {
	
		cout << x[i] << endl;
	}
	
	return 0;
}
