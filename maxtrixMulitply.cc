#include <iostream>
#include <stddef.h>
using namespace std;

void matrixMultiply(int A[4][2], int B[2][6] , int m1, int n1, int m2, int n2) {
			if (!A || !B)
				return;
			if (n1 != m2)
				return;
			int ret[4][6];

		//	ret = new int*[m1];
		//	for (int i = 0; i < m1; ++i)
		//		ret[i] = new int[n2];

			for (int i = 0; i < m1; ++ i) {
				for (int j = 0; j < n2; ++j) {
						int tmp = 0;
						for (int k = 0; k < m2; ++k) {
							tmp += (A[i][k] * B[k][j]);
						}
						ret[i][j] = tmp;
				}

			}
		for(int i = 0; i < m1; ++i) {
			for(int j = 0; j < n2; ++j) 
				cout << ret[i][j] << " ";
			cout << endl;
		}
	return;
}

int main (int argc, char** argv) {
		int a = 2;
		int b = 2;
		int A[4][2] = {1, 2, 3, 4, 5, 6, 7, 8};
		int B[2][6] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
		for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 6; ++j) cout << B[i][j] << " ";
				cout << endl;
		}
		//int **C;

		 matrixMultiply(A, B, 4, 2, 2, 6);
/*
		for(int i = 0; i < a; ++i) {
			for(int j = 0; j < b; ++j) 
				cout << C[i][j] << " ";
			cout << endl;
		}*/
}
