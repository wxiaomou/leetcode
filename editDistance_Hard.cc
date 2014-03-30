#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public: 
	int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> tmp(n + 1, INT_MAX);
        vector<vector<int>> dp(m + 1, tmp);
        // When both of the strings are of size 0, the cost is 0. When only one of the string is zero, 
        // we need edit operations as that of non-zero length string. Mathematically,
        // E(0, 0) = 0, E(i, 0) = i, E(0, j) = j
        for (int j = 0; j <= n; j++) dp[0][j] = j; // j means, if start from here, need to delete j elements in word2 first, so the cost is j here
        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min( dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) ) + 1;// i-1 & j-1 is replacement, i - 1 is deleting in word1, j - 1 is inserting in word1, only consern change in one word.
                }
            }
        }
        return dp[m][n];
    }

    
	//---------------------------------------//
	int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();
		int A[m + 1][n + 1];
		for (int i = 0; i < m + 1; ++i) A[i][0] = i;
		for (int i = 0; i < n + 1; ++i) A[0][i] = i;
	
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (word1[i - 1] == word2[j - 1])
					A[i][j] = A[i - 1][j - 1];
				else
					A[i][j] = 1 + min(min(A[i - 1][j - 1], A[i - 1][j]), A[i][j - 1]);
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		cout << A[0][1] << endl;
		return A[m][n];
	}
};

int main(int argc, char** argv) {
	Solution sol;
	cout << sol.minDistance("", "a") << endl;
	return 1;
}

