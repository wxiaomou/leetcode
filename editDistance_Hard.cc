#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public: 
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

