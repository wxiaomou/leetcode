// Reference to http://polythinking.wordpress.com/2013/06/09/leetcode-word-ladder/
class Solution {
public:
     int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 1;
        int ret = INT_MAX;
        if (dict.count(start) > 0) dict.erase(start);
        unordered_set<string> to_erase;
        queue<string> q;
        q.push(start);
        int size = q.size();
        int lev = 1;
        while (q.size()) {
            string cur = q.front();
            for (int i = 0; i < start.length(); i++) {
                string tmp = cur;
                for (char a = 'a'; a <= 'z'; a++) {
                    tmp[i] = a;
                    if (tmp == end) return lev + 1;
                    if (dict.count(tmp) > 0) {
                        q.push(tmp);
                        to_erase.insert(tmp);
                    } 
                }
            }
            q.pop();
            size--;
            if (!size) {
                size = q.size();
                lev++;
                for (auto it = to_erase.begin(); it != to_erase.end(); it++) {
                    string tmp = *it;
                    dict.erase(tmp);
                }
            }
        }
        
        if (ret == INT_MAX) ret = 0;
        return ret;
    }

    
    //--------------------------------------------------------------//
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
                //if(dict.empty()) break; //should not break if dict is empty here, cause end may not in dict, e.g. cog, should be a bug?
                string bk = str;
                for (char c = 'a'; c <= 'z'; c++) {
                    str[i] = c;
                    if (dict.count(str) != 0) {
                        q.push(make_pair(str, len + 1));
                        dict.erase(str);
                        //if(dict.empty()) break;
                    }
                    str = bk;
                }
            }
        }
        return 0;
    }
};

/*
e.g.
start = "hit";
end = "cag";

dict = {"hot", "dot", "lot", "dog", "log", "cog"};

we have two shortest ways:

hit->hot->dot->dog->cog->cag;
hit->hot->lot->log->cog->cag;

if we remove from dict right after we push str in queue ww will miss solutions, but this question is ask for the shortest length so this fine.
After dog->cog, cog is removed from dict so log cannot reach the end. So in question 2 need remove dicts after a level finished.


*/
