public class Solution {
    int maxLen = -1;

    public int longestIncreasingPath(int[][] matrix) {
        int len = matrix.length;
        if (len == 0) return 0;
        int[][] dp = new int[len][matrix[0].length];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                recur(i, j, matrix, dp);
            }
        }
        return maxLen;
    }
    
    int recur(int i, int j, int[][] matrix, int[][] dp) {
        int left = 0, right = 0, top = 0, buttom = 0;
        // System.out.println("i, " + i + " j " + j + " : " + dp[i][j]);
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
            top = recur(i - 1, j, matrix, dp) + 1;
        }
        if (i < matrix.length - 1 && matrix[i][j] < matrix[i + 1][j]) {
            buttom = recur(i + 1, j, matrix, dp) + 1;
        }
        if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
            left = recur(i, j - 1, matrix, dp) + 1;
        }
        if (j < matrix[0].length - 1 && matrix[i][j] < matrix[i][j + 1]) {
            right = recur(i, j + 1, matrix, dp) + 1;
        }
        dp[i][j] = Math.max(dp[i][j], Math.max(top, Math.max(buttom, Math.max(left, right))));
        maxLen = Math.max(maxLen, dp[i][j]);
        return dp[i][j];
    }
}
