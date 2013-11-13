class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (!start.size()) return 0;
        if (start.size() != end.size()) return 0;
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        
        while (q.size()) {
            string str = q.front().first;
            int len = q.front().second;
            if (str == end) return len;
            q.pop();
            for (int i = 0; i < str.length(); i++) {
                if(dict.empty()) break;
                string bk = str;
                for (char c = 'a'; c <= 'z'; c++) {
                    str[i] = c;
                    if (dict.count(str) != 0) {
                        q.push(make_pair(str, len + 1));
                        dict.erase(str);
                        if(dict.empty()) break;
                    }
                    str = bk;
                }
            }
            
        }
        return 0;
    }
};