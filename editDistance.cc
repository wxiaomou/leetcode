class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (!m) return n;
        if (!n) return m;
        int dis[m + 1][n + 1];
        dis[0][0] = 0;
        for (int i = 1; i <= m; i++) dis[i][0] = i;
        for (int j = 1; j <= n; j++) dis[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dis[i][j] = dis[i - 1][j - 1];
                else
                    dis[i][j] = min(dis[i - 1][j - 1], min(dis[i - 1][j], dis[i][j - 1])) + 1;
            }   
        }
        return dis[m][n];
    }
    //-----------------------------------------------------------------------//
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (!m) return n;
        if (!n) return m;
        int matrix[m + 1][n + 1];
        matrix[m][n] = 0;
        for (int i = m - 1; i >= 0; i--) matrix[i][n] = m - i;
        for (int j = n - 1; j >= 0; j--) matrix[m][j] = n - j;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j])
                    matrix[i][j] = matrix[i + 1][j + 1];
                else 
                    matrix[i][j] = min(matrix[i + 1][j + 1], min(matrix[i + 1][j], matrix[i][j + 1])) + 1;
            }
        }
        return matrix[0][0];
    //----------------------------------------------------------------------//
         int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (!m || !n) return m ? m : n;
        vector<int> tmp(n, INT_MAX);
        vector<vector<int>> ref(m, tmp);
        dp(word1, word2, m, n, ref, 0, 0);
        return ref[0][0];
    }
    
    int dp(string &word1, string word2, int m, int n, vector<vector<int>>& ref, int i, int j) {
        if (i == m) return n - j;
        if (j == n) return m - i;
        if (ref[i][j] != INT_MAX) return ref[i][j];
        if (word1[i] == word2[j]) {
            ref[i][j] = dp(word1, word2, m, n, ref, i + 1, j + 1);
        } else {
            ref[i][j] = min(dp(word1, word2, m, n, ref, i + 1, j + 1), min(dp(word1, word2, m, n, ref, i + 1, j), dp(word1, word2, m, n, ref, i, j + 1)) ) + 1;
        }
        return ref[i][j];
    }
};