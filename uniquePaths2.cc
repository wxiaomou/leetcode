#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size() == 0)
			return 1;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] == 1)
			return 0;

    	int dp[m][n];
		dp[m - 1][n - 1] = 1;
		for (int i = m - 2; i >= 0; i--) {
			if (obstacleGrid[i][n - 1] == 1)
				dp[i][n - 1] = 0;
			else 
				dp[i][n - 1] = dp[i + 1][n - 1];
		}
		for (int j = n - 2; j >= 0; j--) {
			if (obstacleGrid[m - 1][j] == 1)
				dp[m - 1][j] = 0;
			else 
				dp[m - 1][j] = dp[m - 1][j + 1];
		}
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				if (obstacleGrid[i][j] != 1)
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
				else 
					dp[i][j] = 0;
			}
		}
		return dp[0][0];
	}
	/*
	 int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        int matrix[m][n];
        if (obstacleGrid[m - 1][n - 1]) return 0;
        matrix[m - 1][n - 1] = 1;
        for ( auto i = m - 2; i >= 0; --i ) {
            if (obstacleGrid[i][n - 1] != 1 && matrix[i + 1][n - 1] == 1)
                matrix[i][n - 1] = 1;
            else
                matrix[i][n - 1] = 0;
        }
        for ( auto j = n - 2; j >= 0; --j ) {
            if (obstacleGrid[m - 1][j] != 1 && matrix[m - 1][j + 1] == 1)
                matrix[m - 1][j] = 1;
            else
                matrix[m - 1][j] = 0;
        }
        
        for ( auto i = m - 2; i >= 0; --i ) {
            for ( auto j = n - 2; j >= 0; --j ) {
                if ( obstacleGrid[i][j] == 1) {
                    matrix[i][j] = 0;
                    continue;
                }
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        return matrix[0][0];
    }
	*/
};

int main(int argc, char **argv) {
	return 0;
}
