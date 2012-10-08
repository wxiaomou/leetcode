#include <iostream>

using namespace std;
#define N_Max  = 5;

void printMatrix(int A[][5], int m, int n, int k) {
			if (m <= 0 || n <= 0)
				return;

			if (m == 1) {
				for (int i = 0; i < n; ++i)
					cout << A[k][k + i] << " ";
			}

			if (n == 1) {
				for (int i = 0; i < m; ++i)
					cout << A[k + i][k] << " ";
			}

			for (int i = 0; i < n - 1; ++i) {
					cout << A[k][k + i] << " ";
			}

			for (int j = 0; j < m - 1; ++j) {
					cout << A[k + j][k + n  - 1] << " ";
			}

			for (int i = n - 1; i > 0; --i ) {
					cout << A[k + m - 1][k + i] << " ";
			}

			for (int j = m - 1; j > 0; --j) {
					cout << A[k + j][k] << " ";
			}

			printMatrix(A, m - 2, n - 2, k + 1);

}


int main(int argc, char **argv) {
int A[4][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	printMatrix(A, 4, 5, 0);

	return 0;


}
