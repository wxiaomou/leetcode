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
};