#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
        int n = num.size();
        if (!n) return vector<vector<int>>();
        vector<bool> ref(n, false);
        return _permute(num, ref);
    }
    vector<vector<int> > _permute(vector<int> &num, vector<bool> &ref) {
        vector<vector<int>> ret;
        vector<vector<int>> tmp;
        for ( auto i = 0; i < num.size(); ++i ) {
            if (!ref[i]) {
                ref[i] = true;
                tmp = _permute(num, ref);
                for ( auto j = 0; j < tmp.size(); ++j) {
                    tmp[j].insert(tmp[j].begin(), num[i]);
                }
                ret.insert(ret.end(), tmp.begin(), tmp.end());
                ref[i] = false;
            }
        }
        if (!tmp.size()) ret.push_back(vector<int>());
        return ret;
    }
    //--------------------------------------------//
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		if (!num.size())
			return res;
		bool m[num.size()];
		for (int i = 0; i < num.size(); ++i) m[i] = false;
		res = recursion(num, m);

	}
	vector<vector<int> > recursion(vector<int> &num, bool *m) {
		vector<vector<int> > res;
			if (!num.size())
				return res;
		
			for (int i = 0; i < num.size(); i++) {
				if (!m[i]) {
					m[i] = true;
					vector<vector<int> > tmp = recursion(num, m);
					if (tmp.size()) {
						for (int j = 0; j < tmp.size(); ++j) {
							tmp[j].insert(tmp[j].begin(), num[i]);
						}
					} else {
						vector<int> tmp1(1, num[i]);
						tmp.push_back(tmp1);
					}
					res.insert(res.end(), tmp.begin(), tmp.end());
					m[i] = false;
				} else
					continue;
			}
			return res;
	}
};

int main(int argc, char **argv) {
	return 0;
}
