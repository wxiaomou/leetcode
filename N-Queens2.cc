#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
		int res;
    int totalNQueens(int n) {
		if (!n)
			return 0;
		int occup[n];
		res = 0;
		recursion(n, 0, occup);
		return res;
	}

	void recursion(int n, int left,int* occup) {
		if (left == n) {
			res ++;
		}
		
		for (int i = 0; i < n; ++i) {
			bool valid = true;

			for (int k = 0; k < left; k ++) {
				if (occup[k] == i || abs(occup[k] - i) == abs(k - left)) {
					valid = false;
					break;
				} 
			}

			if (valid) {
				occup[left] = i;
				recursion(n, left + 1, occup);
			}
            
		}
	}


};
