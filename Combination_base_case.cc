#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
