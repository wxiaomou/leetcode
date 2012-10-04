#include<iostream>

using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (!n)
			return true;

		int m = 0;

		for (int i = 0; i <= m; ++i) {
			if (m >= n - 1)
				break;
			m = m > (i + A[i]) ? m : (i + A[i]);
		}

		return m >=i n - 1;
	}


};
