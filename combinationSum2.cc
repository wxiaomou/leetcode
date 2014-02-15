class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        int n = candidates.size();
        if (!n) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        return comb(candidates, target, 0);
    }

    vector<vector<int>> comb(vector<int> &candidates, int target, int begin) {
        int n = candidates.size();
        vector<vector<int>> ret;
        
        // next bits should be all fromg begin num[i] < target and no duplication at this bit. not all combination should be the same length.
        for (int i = begin; i < n; ) {
            if (candidates[i] == target) {
                ret.push_back(vector<int>(1, target));
                return ret;
            }
            if (candidates[i] < target) {
                vector<vector<int>> tmp = comb(candidates, target - candidates[i], i + 1);
                if (tmp.size()) {
                    for (int j = 0; j < tmp.size(); j++) {
                        tmp[j].insert(tmp[j].begin(), candidates[i]);
                    }
                    ret.insert(ret.end(), tmp.begin(), tmp.end());
                }
            }
            int ref = candidates[i];
            while (ref == candidates[i]) i++;
            if (candidates[i] > target) break;
        }
        return ret;
    }


};