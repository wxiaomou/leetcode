public class Solution {
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> ret = new ArrayList<>();
        int m = matrix.length;
        if (m == 0) return ret;
        int n = matrix[0].length;
        boolean[][] dp1 = new boolean[m][n];
        boolean[][] dp2 = new boolean[m][n];
        Queue<int[]> q1 = new LinkedList<>();
        Queue<int[]> q2 = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp1[i][j] = false;
                dp2[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            dp1[i][0] = true;
            dp2[i][n - 1] = true;
            
            int[] tmp1 = new int[2];
            tmp1[0] = i;
            tmp1[1] = 0;
            q1.add(tmp1);
            
            int[]tmp2 = new int[2];
            tmp2[0] = i;
            tmp2[1] = n - 1;
            q2.add(tmp2);           
        }
        for (int j = 0; j < n; j++) {
            dp1[0][j] = true;
            dp2[m - 1][j] = true;
            
            int[] tmp1 = new int[2];
            tmp1[0] = 0;
            tmp1[1] = j;
            q1.add(tmp1);
            
            int[]tmp2 = new int[2];
            tmp2[0] = m - 1;
            tmp2[1] = j;
            q2.add(tmp2); 
        }
        bfs(matrix, dp1, q1);
        bfs(matrix, dp2, q2);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp1[i][j] && dp2[i][j]) {
                    int[] tmp = new int[2];
                    tmp[0] = i;
                    tmp[1] = j;
                    ret.add(tmp);
                }
            }
        }
        return ret;
    }
    private void bfs(int[][] matrix, boolean[][] dp, Queue<int[]> q) {
        int m = dp.length;
        int n = dp[0].length;
        int[][] dirs = {{0,-1},{-1,0},{0,1},{1,0}};
        while (!q.isEmpty()) {
            int[] pos = q.poll();
            for (int[] dir : dirs) {
                int x = pos[0] + dir[0];
                int y = pos[1] + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || dp[x][y] || matrix[x][y] < matrix[pos[0]][pos[1]]) {
                    continue;
                }
                dp[x][y] = true;
                int[] tmp = new int[2];
                tmp[0] = x;
                tmp[1] = y;
                q.add(tmp);
            }
        }
    }
}
