#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int i = 0;
    	int j = matrix[0].size() - 1;

		while (j >= 0 && i < matrix.size()) {
			if (matrix[i][j] > target)
				j--;
			else if(matrix[i][j] < target)
				i++;
			else 
				return true;
		}
		return false;
	}

	//-------------------------------------------------------------//
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) return false;
            if (j == n - 1) {
                j = 0;
                i++;
            } else if (i < m - 1 && matrix[i + 1][j] <= target) {
                i++;
                continue;
            } else if (j < n - 1 && matrix[i][j + 1] <= target) {
                j++;
                continue;
            } else {
                return false;
            }
        }
        return false;
    }
};


int main(int argc, char **argv) {
	return 0;
}
