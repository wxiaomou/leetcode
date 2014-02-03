gi
        int _max = 0;
        for ( auto i = 0; i < m; ++i ) {
            for ( auto j = 0; j < n; j++ ) {
                int h = INT_MAX;
                int j1 = j;
                while (j < n && matrix[i][j1] == '1') {
                    int h1 = 0;
                    int i1 = i;
                    while (i1 < m && matrix[i1][j1] == '1') {
                        ++i1;
                        h1++;
                    }
                    h = min(h, h1);
                    j1++;
                    _max = max(_max, h * (j1 - j));
                }
                   
            }
        }
        return _max;
}

/* java solution
public class Solution {
  public int maximalRectangle(char[][] matrix) {
    	int m = matrix.length;
    	if (m == 0) return 0;
    	int n = matrix[0].length;
    	if (n == 0) return 0;
    	int max = 0;
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			int tmp = maxRect(i, j, matrix);
    			max = max > tmp ? max : tmp;
    		}
    	}
    	
    	return max;
    }
    
    private int maxRect(int row, int col, char[][] matrix) {
    	int m = matrix.length;
    	if (m == 0) return 0;
    	int n = matrix[0].length;
    	if (n == 0) return 0;
    	int max = 0;
    	int minWidth = Integer.MAX_VALUE;
    	for (int i = row; i < m && matrix[i][col] == '1'; i++) {
    		int width = 0;
    		while (col + width < n && matrix[i][col + width] == '1') width++;
    		minWidth = Math.min(minWidth, width);
    		int tmp = minWidth * (i - row + 1);
    		max = max > tmp ? max : tmp;
    	}
    	return max;
    }
}*/