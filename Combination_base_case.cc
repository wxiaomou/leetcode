#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	 vector<vector<int> > combine(int n, int k) {
        if (!n) return vector<vector<int>> ();
        bool ref[n];
        for (int i = 0; i < n; i++) ref[i] = false;
        vector<vector<int>> ret;
        _com(n, k, 0, vector<int>(), ret);
        return ret;
    }
    
    void _com(int n, int k, int i, vector<int> pre, vector<vector<int>> &ret) {
        if (!k)  {
            ret.push_back(pre);
            return;
        }
        if (i == n) return;
        _com(n, k, i + 1, pre, ret);
        pre.push_back(i + 1);
        _com(n, k - 1, i + 1, pre, ret);
    }
	//----------------------------------------------//
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > ret;
			if (n < 1 || k < 1)
				return ret;
			if (n < k)
				return ret;
			if (k == 1) {
				vector<int> tmp;
				tmp.push_back(n);
				ret.push_back(tmp);
			}

			vector<vector<int> > ret_tmp = combine(n - 1, k - 1);
			for (int i = 0; i < ret_tmp.size(); ++i) {
				ret_tmp[i].push_back(n);
				ret.push_back(ret_tmp[i]);
			}

			ret_tmp = combine(n - 1, k);
			for (int i = 0; i < ret_tmp.size(); i++) {
				ret.push_back(ret_tmp[i]);
			}
			return ret;
    }
};

int main(int argc, char **argv) {
	Solution sol;
	vector<vector<int> > res = sol.combine(4, 2);
	for (int i = 0; i < res.size(); ++i) {
			vector<int> tmp = res[i];
			for (int j = 0; j < tmp.size(); ++j) {
				cout << tmp[j] << " ";
			}
			cout << endl;
	}
	return 1;
}
