#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m== 1 || n == 1)
            return 1;
       int dp[m][n];
    //	memset(dp, 0, sizeof(int)*m*n); not word
		for (int i = 0; i < m; i++) dp[i][n - 1] = 1;
		for (int j = 0; j < n; j++) dp[m - 1][j] = 1;
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
			}
		}
		return dp[0][0];
	}
	

	int uniquePaths2(int m, int n) {
		if (m == 1 || n == 1)
			return 1;
		int count = 0;
		count += uniquePaths(m - 1, n);
		count += uniquePaths(m, n - 1);
		return count;
	}
};

int main(int argc, char **argv) {
	Solution sol;
	sol.uniquePaths(3,7);

	return 0;
}
