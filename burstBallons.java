public class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] newNums = new int[n + 2];
        newNums[0] = 1;
        newNums[n + 1] = 1;
        int[][] dp = new int[n + 2][n + 2];
        for (int i = 1; i <= n; i++) { newNums[i] = nums[i - 1]; }
        for (int len = 1; len <= n; len++) {
            for (int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;
                // k is the last burst balloon in this subarray.
                for (int k = left; k <= right; k++) {
                    dp[left][right] = Math.max(dp[left][right], newNums[left - 1] * newNums[k] * newNums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
}
