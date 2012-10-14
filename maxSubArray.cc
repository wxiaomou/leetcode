#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
       if (0 == n) return 0;
    	int cur_sum = 0;
		int m_max = -100000;

		for (int i = 0; i < n; ++i) {
			cur_sum += A[i];

	    	m_max = max(cur_sum, m_max);
           
			if (cur_sum < 0) {
				cur_sum = 0;
			}
		}

		return m_max;
	}
};

int main(int argc, char **argv) {
	return 0;
}
