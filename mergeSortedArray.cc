#include <iostream>

using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (k >= 0) {
            if (i >= 0 && j >= 0) {
                A[k--] = A[i] > B[j] ? A[i--] : B[j--]; 
            } else if (i >= 0) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        return;
    }
	//------------------------------------------//
	void merge(int A[], int m, int B[], int n) {
	 	int k = m + n - 1;
    	int i = m - 1;
		int j = n - 1;

		while (i >= 0 && j >= 0) {
			if (A[i] > B[j]) {
				A[k--] = A[i--];
			} else {
				A[k--] = B[j--];
			}
		}

		int p = i >= 0 ? i : j;
		int *tmp = i >= 0 ? A : B;
		while (p >= 0) A[k--] = tmp[p--];
	}
};

int main(int argc, char **argv) {
	return 0;
}
