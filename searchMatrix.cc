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
};


int main(int argc, char **argv) {
	return 0;
}
