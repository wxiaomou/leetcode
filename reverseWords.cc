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
//---------------------------------------//
    void reverseWords(string &s) {
        int n = s.length();
        reverse(s);
        string ret = "";
        for (int i = 0; i < n;) {
            while (i < n && s[i] == ' ') i++;
            if (i < n) {
                int j = i + 1;
                while (j < n && s[j] != ' ') j++;
                string tmp = s.substr(i, j - i);
                reverse(tmp);
                ret += " " + tmp;
                i = j;
            }
        }
        if (!ret.length()) s = ret;
        else s = ret.substr(1);
    }
    
    void reverse(string &s) {
        int n = s.length();
        if (!n) return;
        for (int i = 0; i < n / 2; i++) {
            char tmp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = tmp;
        }
    }
