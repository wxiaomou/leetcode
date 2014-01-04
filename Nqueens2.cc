#include <iostream>
#include <math.h>
using namespace std;
class Solution {
	public:
		int totalNQueens(int n) {
			if (n <= 0) return 0;
			int used[n];
			return doRecur(0, n, used);
        }

		int doRecur(int i, const int n, int *used) {
			if (n == i)
				return 1;
			int ret = 0; 
			for (int j = 0; j < n; j++) {
				bool found = true;
				for (int k = 0; k < i; k++) {
					if (used[k] == j || (abs(i - k) == abs(j - used[k]))) {
						found = false;
						break;
					}
				}

				if (found) {
					used[i] = j;
					ret += doRecur(i + 1, n, used);
				}

			}
			return ret;
		}
};

int main() {
	return 0;
}
