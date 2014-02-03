#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
    vector<int> ret;
		if (!n) {
        ret.push_back(0);
			return ret;
		}
		if (n == 1) {
			ret.push_back(0);
			ret.push_back(1);
			return ret;
		}
		int cur = 1 << (n - 1);
		vector<int> tmp = grayCode(n - 1);
		ret = tmp;
		for (int i = tmp.size() - 1; i > -1; --i) {
			tmp[i] |= cur;
			ret.push_back(tmp[i]);
		}
		return ret;
	}

	//--------------------------------------------//
	 vector<int> grayCode(int n) {
        vector<int> ret(1, 0);
        unordered_set<int> hash;
        int cur = 0;
        hash.insert(0);
        int total = pow(2, n);
        while (ret.size() < total) {
            for (int i = 0; i < n; i++) {
                int tmp = cur ^ (1 << i);
                if (hash.count(tmp) == 0) {
                    ret.push_back(tmp);
                    hash.insert(tmp);
                    cur = tmp;
                    break;
                }
            }
        }
        return ret;
    }

};

int main(int argc, char** argv) {
	Solution sol;
	vector<int> tmp = sol.grayCode(2);
	for (int i = 0; i < tmp.size(); ++i) {
			cout << tmp[i] << endl;
	}
	return 1;
}
