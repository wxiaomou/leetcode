public class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        if (n == 0) return 0;
        int L = matrix[0][0], R = matrix[n - 1][n - 1];
        while (L < R) {
            int mid = (L + R) / 2;
            int tmp = search_lower_than_mid(matrix, mid);
            if (tmp < k) L = mid + 1;
            else R = mid;
        }
        return R;
	}
	
	private int search_lower_than_mid(int[][] matrix, int x) {
        int n = matrix.length;
        int i = n - 1, j = 0;
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= x) {
                j++;
                cnt += i + 1;
            } else {
                i--;
            }
        }
        return cnt;
	}
}
