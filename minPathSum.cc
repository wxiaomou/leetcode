#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        vector<int> tmp(n, 0);
        vector<vector<int>> ret(m, tmp);
        ret[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--) ret[i][n - 1] = grid[i][n - 1] + ret[i + 1][n - 1];
        for (int j = n - 2; j >= 0; j--) ret[m - 1][j] = grid[m - 1][j] + ret[m - 1][j + 1];
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                ret[i][j] = grid[i][j] + min(ret[i + 1][j], ret[i][j + 1]);
            }
        }
        return ret[0][0];
    }
	//---------------------------------------//
	int **matrix;		
	int minPathSum(vector<vector<int> > &grid) {
    	if (grid.size() == 0)
    		return 0;

		int m = grid.size();
		int n = grid[0].size();
		matrix = new int *[m];
		for (int i = 0; i < m; ++i) matrix[i] = new int[n];
			
		matrix[m - 1][n - 1] = grid[m - 1][n - 1];
		for (int i = m - 2; i >= 0; i--) 
			matrix[i][n - 1] = grid[i][n - 1] + matrix[i + 1][n - 1];

		for (int j = n - 2; j >= 0; j--)
			matrix[m - 1][j] = grid[m - 1][j] + matrix[m - 1][j + 1];
				
		int i = m - 2;
		int j = n - 2;
		while (i >= 0) {
			while (j >= 0) {
				matrix[i][j] = grid[i][j] + min(matrix[i][j + 1], matrix[i + 1][j]);
                    j--;
			}
    		j = n - 2;
			i--;
		}
		return matrix[0][0];
        
	}

    int minPathSum2(vector<vector<int> > &grid) {
    	if (grid.size() == 0)
			return 0;

		int m = grid.size();
		int n = grid[0].size();
		matrix = new int *[m];
		for (int i = 0; i < m; ++i) matrix[i] = new int[n];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = -1;

		dp(matrix, 0, 0, grid);
		return matrix[0][0];
	}

	int dp(int **m, int i, int j, vector<vector<int> > grid) {
		if (i >= grid.size()  || j >= grid[0].size())
			return 0;
            
        if (m[i][j] != -1)
			return m[i][j];
		
		if (i == grid.size() - 1) {
			m[i][j] = grid[i][j] + dp(m, i, j + 1, grid);
			return m[i][j];
		}
		if (j == grid[0].size() - 1) {
			m[i][j] = grid[i][j] + dp(m, i + 1, j, grid);
			return m[i][j];
		}
	
		m[i][j] = grid[i][j] + min(dp(m, i + 1, j, grid), dp(m, i, j + 1, grid));

		return m[i][j];
	}
};

int main(int argc, char **argv) {
	return 0;
}
