#include<iostream>
using namespace std;
class Solution {
public: 
	int climbStaris(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		if (n < 1)
			return 0;
		int a = 1;
		int b = 2;
		for (int i = 3; i <= n; ++i) {
			int tmp = a + b;
			a = b;
			b = tmp;
		}
		return b;
	}
};
