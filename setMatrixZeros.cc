#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (!matrix.size())
			return;

		bool firstRow = false;
		bool firstCol = false;

		for (int i = 0; i < matrix[0].size(); i++) {
			if (matrix[0][i] == 0) {
				firstRow = true;
				break;
			}
		}

		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[i][0] == 0) {
				firstCol = true;
				break;
			}
		}

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (!matrix[i][0] || !matrix[0][j]) {
					matrix[i][j] = 0;
				}
			}
		}

		if (firstRow) {
			for (int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
		}

		if (firstCol) {
			for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
		}

		return;
	}


	/* O(m + n) space
	void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (!m) return;
        int n = matrix[0].size();
        unordered_set<int> row;
        unordered_set<int> col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for ( auto i = row.begin(); i != row.end(); i++) {
            for ( auto j = 0; j < n; ++j) matrix[*i][j] = 0;
        }
        
        for ( auto j = col.begin(); j != col.end(); ++j) {
            for ( auto i = 0; i < m; i++) matrix[i][*j] = 0;
        }   
    }
	*/
};

int main(int argc, char **argv) {
	return 0;
}
