#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> res;
		if (matrix.size() == 0)
			return res;
		doSpiral(matrix, matrix.size(), matrix[0].size(), 0, res);
		return res;
	}
	void doSpiral(vector<vector<int> > &matrix, int m, int n, int k, vector<int> &res) {
		if (m <= 0 || n <= 0)
			return;
		if (m == 1) {
			for (int i = 0;i < n; i++) res.push_back(matrix[k][k + i]);
            return;
		}
		if (n == 1) {
			for (int j = 0; j < m; j++) res.push_back(matrix[k + j][k]);
            return;
		}

		for (int i = 0; i < n - 1; i++) res.push_back(matrix[k][k + i]);
		for (int j = 0; j < m - 1; j++) res.push_back(matrix[k + j][k + n - 1]);
		for (int i = 0; i < n - 1; i++) res.push_back(matrix[k + m - 1][k + n - 1 - i]);
		for (int j = 0; j < m - 1; j++) res.push_back(matrix[k + m - 1 - j][k]);
		doSpiral(matrix, m - 2, n - 2, k + 1, res);
		return;
	}
};

int main(int argc, char **argv) {
	return 0;
}
