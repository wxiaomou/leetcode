//df reference to http://fisherlei.blogspot.com/2013/03/leetcode-palindrome-partitioning-ii.html
class Solution {
public:
    
    int minCut(string s) {
        if (!s.size()) return 0;
        int n = s.length();
        bool ref[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                ref[i][j] = false;
        int D[n + 1];
        for (int i = 0; i <= n; i++) D[i] = n - i;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if ( (s[i] == s[j]) && ( (j - i < 2) || ref[i + 1][j - 1]) ) {
                    ref[i][j] = true;
                    D[i] = min(D[i], D[j + 1] + 1);
                }
            }
        }
        return (D[0] - 1);
    }
};