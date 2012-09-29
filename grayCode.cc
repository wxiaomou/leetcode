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

};

int main(int argc, char** argv) {
	Solution sol;
	vector<int> tmp = sol.grayCode(2);
	for (int i = 0; i < tmp.size(); ++i) {
			cout << tmp[i] << endl;
	}
	return 1;
}
