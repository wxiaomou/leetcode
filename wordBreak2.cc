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
        string tmp = "";
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
    
};
