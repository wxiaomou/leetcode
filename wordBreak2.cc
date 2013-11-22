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
