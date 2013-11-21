class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!s.size()) return false;
        vector<int> ref(s.size(), -1);
        return _wordBreak(s, dict, ref, 0);
    }
    
    bool _wordBreak(string s, unordered_set<string> &dict, vector<int> &ref, int i) {
        if ( !s.size() ) return true;
        if ( ref[i] != -1) return ref[i];
        for ( int i = 0; i < s.size(); i++ ) {
            if ( dict.find(s.substr(0, i + 1)) != dict.end() ) {
                if ( _wordBreak(s.substr(i + 1), dict, ref, i + 1) ) {
                    ref[i] = 1;
                     return true;
                }
            }
        }
        ref[i] = 0;
        return false;
    }
};