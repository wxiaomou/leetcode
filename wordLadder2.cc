// still not faset enough
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) vector<vector<string>>();
        
        if (dict.count(start) > 0) dict.erase(start);
        if (dict.count(end) > 0) dict.erase(end);
        
        vector<vector<string>> ret;
        queue<vector<string>> q;
        vector<string> a(1, start);
        q.push(a);
        int size = 1, lev = 1, final = INT_MAX;
        unordered_set<string> to_remove;
        while (q.size() && lev < final) {
            vector<string> cur = q.front();
            for (int i = 0; i < start.length(); i++) {
                string tmp = cur[cur.size() - 1];
                for (char a = 'a'; a <= 'z'; a++) {
                    tmp[i] = a;
                    if (tmp == end) {
                        vector<string> cur1 = cur;
                        cur1.push_back(tmp);
                        ret.push_back(cur1);
                        if (final == INT_MAX)
                            final = lev + 1;
                    }
                    if (dict.count(tmp) > 0) {
                        vector<string> cur1 = cur;
                        cur1.push_back(tmp);
                        q.push(cur1);
                        to_remove.insert(tmp);
                    }
                }
            }
            q.pop();
            size--;
            if (!size) {
                size = q.size();
                for (auto it = to_remove.begin(); it != to_remove.end(); it++) {
                    dict.erase(*it);
                }
                to_remove.clear();
                lev++;
            }
        }
        return ret;
    }
};