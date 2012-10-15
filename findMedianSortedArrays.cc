#include <iostream>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (!m) {
			if (n % 2) {
				return B[n / 2] * 1.0;
			} else {
				return (double)(B[n / 2 - 1] + B[n / 2]) / 2;
			}
		} else if (!n) {
			if (m % 2) {
				return A[m / 2] * 1.0;
			} else {
				return (double)(A[m / 2 - 1] + A[m / 2]) / 2.0;
			}
		}

		int C[m + n];
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < m || j < n) {
			if (i == m) {
				while (j < n) {
					C[k] = B[j];
					j++;
					k++;
				}
			} else if (j == n) {
				while (i < m) {
					C[k] = A[i];
					i++;
					k++;
				}
			}
			if (A[i] > B[j]) {
				C[k] = B[j];
				k++;
				j++;
			} else {
				C[k] = A[i];
				i++;
				k++;
			}

		}
		if ((m + n) % 2) 
			return C[(m + n) / 2] * 1.0;
		else 
			return (double)(C[(m + n) / 2 - 1] + C[(m + n) / 2]) / 2.0;
	}
};


int main(int argc, char **argv) {
	return 0;

}
