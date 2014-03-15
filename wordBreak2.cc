/* time limit exceed
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (!s.size()) return vector<string>();
        return _break(s, dict, 0);
     }
    
    vector<string> _break(string &s, unordered_set<string> &dict, int start) {
        if (start >= s.size()) return vector<string>();
        vector<string> ret;
        for (int i = start; i < s.size(); i++) {
            vector<string> tmp;
            if ( dict.find(s.substr(start, i - start + 1)) != dict.end() ) {
                tmp = _break(s, dict, i + 1);
                for (int j = 0; j < tmp.size(); j++) {
                    tmp[j] = s.substr(start, i - start + 1) + " " + tmp[j];
                }
                ret.insert(ret.end(), tmp.begin(), tmp.end());
            }
        }
        return ret;
    }
     
};*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        if (!n) return vector<string> ();
        bool **ref = new bool*[n];
        for (int i = 0; i < n; i++) ref[i] = new bool[n + 1];
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                ref[i][j] = false;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int len = 1; len <= n - i; len++) {
                if (dict.count(s.substr(i, len)) > 0) 
                    ref[i][len] = true;
                
                for (int k = 1; k < len; k++) {
                    if (ref[i][k] && ref[i + k][len - k])
                        ref[i][len] = true;
                }
            }
        }
        if (!ref[0][n]) return vector<string>();
        string tmp = "";gi
        dfs(s, 0, tmp, dict, ref, ret);
        return ret;
    }
    
    void dfs(string s, int i, string tmp, unordered_set<string> &dict, bool **ref, vector<string> &ret) {
        int n = s.length();
        if (i == n) {
            tmp = tmp.substr(0, tmp.length() - 1);
            ret.push_back(tmp);
            return;
        }
        
        for (int len = 1; len <= n - i; len++) {
            if (ref[i][len]) {
                if (dict.count(s.substr(i, len))) {
                    int len_before = tmp.length();
                    tmp += s.substr(i, len);
                    tmp += " ";
                    dfs(s, i + len, tmp, dict, ref, ret);
                    tmp = tmp.substr(0, len_before);
                }
            }
        }
        return;
    }

    //-----------------------------------------------//
     vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        if (!n) return vector<string>();
        vector<bool> tmp(n, false);
        vector<vector<bool>> dp(n, tmp);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (dict.count(s.substr(i, j - i + 1)) > 0) {
                    dp[i][j] = true;
                    continue;
                }
                for (int k = i; k < j; k++) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        if (!dp[0][n - 1]) return vector<string>();
        vector<string> ret;
        dfs(s, 0, ret, "", dp, dict);
        return ret;
    }
    
    void dfs(string &s, int start, vector<string> &ret, string tmp, vector<vector<bool>> &dp, unordered_set<string> &dict) {
        int n = s.length();
        if (start == n) {
            ret.push_back(tmp.substr(0, tmp.length() - 1));   
            return;
        }
        for (int len = 1; start + len <= n; len++) {
            if (dict.count(s.substr(start, len)) > 0) {
                if (dp[start][start + len - 1]) {
                    int len_before = tmp.length();
                    tmp += s.substr(start, len);
                    tmp += " ";
                    dfs(s, start + len, ret, tmp, dp, dict);
                    tmp = tmp.substr(0, len_before);
                }
            }
        }
        return;
    }
    
};
