#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray2(int A[], int n) {
		if (0 == n) return 0;
		int cur_sum = 0;
		int m_max = 0;

		for (int i = 0; i < n; ++i) {
			cur_sum += A[i];

			if (cur_sum < 0) {
				cur_sum = 0;
			}

		m_max = max(cur_sum, m_max);
		}

		return m_max;
	}

	    int maxSubArray(int A[], int n) {
        if (1 == n)
    		return A[0];

		int mid = n / 2;
		int left_mid = maxSubArray(A, mid);
		int right_mid = maxSubArray(A + mid, n - mid);
		int cur_left = A[mid - 1];
		int cur_right = A[mid];
		int tmp = 0;
		for (int i = mid - 1; i >= 0; --i) {
			tmp += A[i];
			cur_left = max(cur_left, tmp);
		}
		tmp = 0;

		for (int i = mid; i < n; ++i) {
			tmp += A[i];
			cur_right = max(cur_right, tmp);
		}
		int res = cur_left + cur_right;
		return max(max(left_mid, right_mid), res);
        
    }
};

int main(int argc, char **argv) {
	return 0;
}
