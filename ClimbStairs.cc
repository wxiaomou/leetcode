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
		for (int i = 3; i <= n; ++i) { //!!!attention
			int tmp = a + b;
			a = b;
			b = tmp;
		}
		return b; // should return b
	}

	//---------------------------------//
	int climbStairs(int n) {
        if (!n) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int ref[n];
        ref[n - 1] = 1;
        ref[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--) {
            ref[i] = ref[i + 1] + ref[i + 2];
        }
        return ref[0];
    }
};
};
