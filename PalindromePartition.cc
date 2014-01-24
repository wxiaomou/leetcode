vector<vector<string>> partition(string s) {
        int n = s.length();
        if (!n) return vector<vector<string>>();
        return _partition(s, 0);
    }
    
    vector<vector<string>> _partition(string s, int start) {
        int n = s.size();
        vector<vector<string>> ret;
        if (n <= start) {
            ret.push_back(vector<string> ());
            return ret;
        }
        int i = 0; 
        while (start + i < n) {
            if (isPalin(s, start, start + i)) {
                vector<vector<string>> tmp = _partition(s, start + i + 1);
                for (int j = 0; j < tmp.size(); j++) {
                    tmp[j].insert(tmp[j].begin(), s.substr(start, i + 1));
                }
                ret.insert(ret.end(), tmp.begin(), tmp.end());
            }
            i++;
        }
        return ret;
    }
    
    bool isPalin(string s, int start, int end) {
        int n = s.size();
        if (!n) return true;
        int i = 0;
        while (end - i > start + i) {
            if (s[start + i] != s[end - i]) return false;
            i++;
        }
        return true;
    }
};