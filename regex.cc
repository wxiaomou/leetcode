class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        if (*(p + 1) != '*') {
            if (*s == *p || *p == '.' && *s != 0) //*s != 0 is for special case like s = "", p = '.', which we can refer the commented function.
                return isMatch(s + 1, p + 1);
            else 
                return false;
        } else {
            while (*s == *p || (*p == '.' && *s != 0)) { // s will increase so need to check *s != 0
                if (isMatch(s, p + 2)) return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }

    //-----------------------------//
    bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        int m = strlen(s), n = strlen(p);
        vector<int> tmp(n, -1);
        vector<vector<int>> dp(m, tmp);
        return _dp(dp, s, p, 0, 0) == 1;
    }
    
    int _dp(vector<vector<int>> &dp, const char *s, const char *p, int i, int j) {
        int m = strlen(s), n = strlen(p);
        if (j == n) return i == m;
        if (i == m) {
            if (*(p + j + 1) == '*')
                return _dp(dp, s, p, i, j + 2);
            else 
                return 0;
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (j + 1 == n || p[j + 1] != '*') {
            if (s[i] == p[j] || (p[j] == '.' && i < m)) {
                dp[i][j] = _dp(dp, s, p, i + 1, j + 1);
            } else { 
                dp[i][j] = 0;
            }
            return dp[i][j];
        } else {
            while(s[i] == p[j] || (p[j] == '.' && i < m)) {
                if (_dp(dp, s, p, i, j + 2)) {
                    dp[i][j] = 1;
                    return 1;
                }
                i++;
            }
            int tmp = _dp(dp, s, p, i, j + 2);
            if (i < m) 
                dp[i][j] = tmp;
            return tmp;
        }
    }
    /*bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        if (*s == 0) {
            if (*(p + 1) == '*') return isMatch(s, p + 2);
            return false;            
        }
        
        if (*(p + 1) == '*') {
            while ((*s == *p || *p == '.') && *s != 0) { // if *s == *p than '*' will match 1 or more
                if (isMatch(s, p + 2)) return true; 
                s++;
            }
            return isMatch(s, p + 2); //if *s != *p then x* match zero item.
        } else {
            if (*s == *p || *p == '.') return isMatch(s + 1, p + 1);
            return false;
        }
    }
    }*/
};