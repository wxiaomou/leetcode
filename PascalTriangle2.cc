class Solution {
    public:
    vector<int> getRow(int rowIndex) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        // if (!rowIndex) return vector<int>();
        if (rowIndex == 0) return vector<int> (1,1);
        if (rowIndex == 1) return vector<int> (2,1);
        vector<int> ret (2, 1);
        vector<int> ret1;
        for (int i = 2; i <= rowIndex; ++i) {
            if (i % 2 == 0) {
                ret1.push_back(1);
                for (int j = 1; j < ret.size(); j++) {
                    ret1.push_back(ret[j - 1] + ret[j]);
                }
                ret1.push_back(1);
                ret.clear();
            } else {
                ret.push_back(1);
                for (int j = 1; j < ret1.size(); j++) {
                    ret.push_back(ret1[j - 1] + ret1[j]);
                }
                ret.push_back(1);
                ret1.clear();
            }
        }
        return ret.size() > ret1.size() ? ret : ret1;
    }

    //---------------------recursion---------------------------//
     vector<int> getRow(int rowIndex) {
        //if (!rowIndex) return vector<int>();
        if (!rowIndex) return vector<int> (1, 1);
        vector<int> tmp = getRow(rowIndex - 1);
        vector<int> ret;
        int n = tmp.size();
        ret.push_back(1);
        for (int i = 0; i < n - 1; i++) {
            ret.push_back(tmp[i] + tmp[i + 1]);
        }
        ret.push_back(1);
        return ret;
    }
};