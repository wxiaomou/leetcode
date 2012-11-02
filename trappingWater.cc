#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		if (n < 3)
			return 0;
		int l[n];
		int r[n];
		l[0] = A[0];
		for (int i = 1; i < n; i++) {
			l[i] = max(A[i], l[i - 1]);
		}
		r[n - 1] = A[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i + 1], A[i]);
		}
		int  low = 0;
		int count = 0;
		for (int i = 1; i < n - 1; i++) {
			low = min(l[i - 1], r[i + 1]);
			count += (low > A[i]) ? (low - A[i]) : 0;
		}
		return count;
	}
};

int main(int argc, char **argv) {
	return 0;
}
