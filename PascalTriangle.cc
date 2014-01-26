class Solution {
    public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        if (!numRows) return ret;
        for (int i = 1; i <= numRows; ++i) {
            if (i == 1) {
                ret.push_back(vector<int>(1, 1));
            } else if (i == 2) {
                ret.push_back(vector<int>(2, 1));
            } else {
                vector<int> &ref = ret.back();
                vector<int> cur (1,1);
                for (int j = 1; j < ref.size(); j++) {
                    cur.push_back(ref[j - 1] + ref[j]);
                }
                cur.push_back(1);
                ret.push_back(cur);
            }
        }
        return ret;   
    }
    //-----------------------recursion--------------------------//
    vector<vector<int> > generate(int numRows) {
        if (!numRows) return vector<vector<int> >();
        vector<vector<int>> ret;
        _gen(numRows, ret);
        return ret;
    }
    void _gen(int num, vector<vector<int>> &ret) {
        if (!num) return;
        if (!ret.size()) {
            ret.push_back(vector<int>(1,1));
        } else {
            vector<int> tmp;
            int n = ret.size();
            tmp.push_back(1);
            for (int i = 0; i < ret[n - 1].size() - 1; i++) {
                tmp.push_back(ret[n - 1][i] + ret[n - 1][i + 1]);
            }
            tmp.push_back(1);
            ret.push_back(tmp);
        }
        _gen(num - 1, ret);
    }
};