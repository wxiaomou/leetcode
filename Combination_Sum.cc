#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        if (!n) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        return comb(candidates, target, 0);
    }

    vector<vector<int>> comb(vector<int> &candidates, int target, int begin) {
        int n = candidates.size();
        vector<vector<int>> ret;
        
        for (int i = begin; i < n; i++) {
        	if (i > 0 && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] == target) {
                ret.push_back(vector<int>(1, target));
                return ret;
            }
            int ref = target;
            
            if (candidates[i] < ref) {
                vector<vector<int>> tmp = comb(candidates, ref - candidates[i], i);
                
                if (!tmp.size()) continue;
                
                for (int j = 0; j < tmp.size(); j++) {
                    tmp[j].insert(tmp[j].begin(), candidates[i]);
                }
                ret.insert(ret.end(), tmp.begin(), tmp.end());
                ref -= candidates[i];
            }
            if (candidates[i] > target) break;
        }
        return ret;
    }

	//------------------------------------------------------------------------//
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    		vector<vector<int> > ret;
				int size = candidates.size();
				if (size < 1)
					return ret;
				if (target <= 0)
					return ret;
        sort(candidates.begin(), candidates.end());
				int cur = candidates[0];
				int a = target / cur;

				if (target == a * cur) {
					vector<int> tmp;
					for (int i = 0; i < a; ++i) {
						tmp.push_back(cur);
					}
					ret.push_back(tmp);
				}
				candidates.erase(candidates.begin());

				for (int i = 1; i <= a; ++i) {
					vector<vector<int> > ret_tmp = combinationSum(candidates, target - i * cur);
					for (int j = 0; j < ret_tmp.size(); ++j) {
						for (int n = 0; n < i; ++n) {
							ret_tmp[j].insert(ret_tmp[j].begin(), cur);
						}
						ret.push_back(ret_tmp[j]);
					}
				}
				vector<vector<int> >ret_tmp = combinationSum(candidates, target);
				for (int i = 0; i < ret_tmp.size(); ++i) {
					ret.push_back(ret_tmp[i]);
				}
				candidates.insert(candidates.begin(), cur);
				return ret;
		}
};
int main(int argc, char **argv) {
	int a[4] = {2,6,3,7};
	vector<int> test(a, a + 4);
	Solution sol;
	vector<vector<int> > res = sol.combinationSum(test, 7);
	for (int i = 0; i < res.size(); ++i) {
			vector<int> tmp = res[i];
			for (int j = 0; j < tmp.size(); ++j) {
				cout << tmp[j] << " ";
			}
			cout << endl;
	}
	return 1;
}
