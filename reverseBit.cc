#include<iostream>
#include<stdio.h>
using namespace std;

class Solution {
public:
	unsigned int reverseBits(unsigned int tmp) {
		int n = 32;
		for (int i = 0; i < n / 2; ++i) {
			swap(tmp, i, n - i -1);
		}
		return tmp;
	}

	bool swap(unsigned int &x, unsigned int i, unsigned int j) {
		if (i > 32 || j > 32)
			return false;
		
		int hi = x & (1 << i);
		int lo = x & (1 << j);

		if (hi ^ lo) {
			x ^= (1 << i);
			x ^= (1 << j);
		}
	}
};

int main(int argc, char **argv) {
	Solution sol;
	unsigned int a = 1000;
	printf("%x \n", a);
	unsigned int ret = sol.reverseBits(a);
	printf("%x \n", ret);
}
