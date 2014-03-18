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
//------------------------------------//
 bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        int m = strlen(s), n = strlen(p);
        vector<int> tmp(n, -1);
        vector<vector<int>> ref(m + 1, tmp);
        dp(s, 0, m, p, 0, n, ref);
        return ref[0][0];
    }
    
    int dp(const char *s, int i, int m, const char *p, int j, int n, vector<vector<int>> &ref) {
        if (j == n) {
            if (i == m) return 1;
            else return 0;
        }
        if (ref[i][j] != -1) return ref[i][j];
        if (j + 1 < n && p[j + 1] == '*') {
            int k = i;
            while ((s[k] == p[j] || p[j] == '.') && k < m) {
                if (dp(s, k, m, p, j + 2, n, ref) > 0) {
                    return ref[i][j] = 1;
                } 
                k++;
            }
            return ref[i][j] = dp(s, k, m, p, j + 2, n, ref);
        } else {
            if ((s[i] == p[j] || p[j] == '.') && i < m) return ref[i][j] = dp(s, i + 1, m, p, j + 1, n, ref);
            else return ref[i][j] = 0;
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