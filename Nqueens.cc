#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
	public:
		vector<vector<string> > ret;
		vector<vector<string> > solveNQueens(int n) {
			if (n <= 0)
				return ret;
			int row[n];
			for (int i = 0; i < n; i++) row[i] = -1;
			doRecur(0, row, n);
			return ret;
        }
		void doRecur(int i, int *row, const int n) {
			if (i == n) {
				//cout << "n is " << n << endl;
				vector<string> tmp(n * n, ".");
				for (int j = 0; j < n; j++) {
					tmp[n * row[j] + j] = "Q";
				}
				ret.push_back(tmp);
				return;
			}

			for (int j = 0; j < n; j++) {
				bool valid = true;
				for (int k = 0; k < i; k++) {
					if (row[k] == j || (abs(k - i) == abs(row[k] - j))) {
						valid = false;
						break;
					}
				}
				if (valid) {
					row[i] = j;
					doRecur(i + 1, row, n);
					row[i] = -1;
				}
			}
			return;
		}
};

int main() {
	Solution sol;
	int n = 4;
	vector<vector<string> > ret = sol.solveNQueens(n);
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < n * n; j++) {
			cout << " " << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
