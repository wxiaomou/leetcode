void reverseWords(string &s) {
        int n = s.length();
        reverse(s, 0, n - 1);
        string ret = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            int j = i;
            while (j < n && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            ret += s.substr(i, j - i);
            ret += " ";
            i = j;
        }
        if (ret[ret.length() - 1] == ' ') ret = ret.substr(0, ret.length() - 1);
        s = ret;
        return;
    }
    
    void reverse(string &s, int start, int end) {
        if (end <= start) return;
        while (start < end) {
            char tmp = s[end];
            s[end] = s[start];
            s[start] = tmp;
            start++;
            end--;
        }        
        return;
    }
