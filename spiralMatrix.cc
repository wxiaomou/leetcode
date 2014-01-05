#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (!m) return vector<int>();
        int n = matrix[0].size();
        vector<int> ret;
        int row_s = 0, row_e = m - 1, col_s = 0, col_e = n - 1;
        while (row_s <= row_e && col_s <= col_e) {
            if  (row_s == row_e && col_s == col_e) {
                ret.push_back(matrix[row_s][col_s]);
            } else if (row_s == row_e) {
                for (int j = col_s; j <= col_e; j++) ret.push_back(matrix[row_s][j]);
            } else if (col_s == col_e) {
                for (int i = row_s; i <= row_e; i++) ret.push_back(matrix[i][col_e]);
            } else {
                for (int j = col_s; j <= col_e; j++) ret.push_back(matrix[row_s][j]);
                for (int i = row_s + 1; i <= row_e; i++) ret.push_back(matrix[i][col_e]);
                for (int j = col_e - 1; j >= col_s; j--) ret.push_back(matrix[row_e][j]);
                for (int i = row_e - 1; i > row_s; i--) ret.push_back(matrix[i][col_s]);
            }
            row_s++;
            row_e--;
            col_s++;
            col_e--;
        }
        return ret;
    }
	//----------------------------------------------------------//
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
