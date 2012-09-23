#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    	int size = num.size();
			vector<vector<int> > ret;
			if (size < 1) return ret;
			if (target <= 0) return ret;
			sort(num.begin(), num.end());
			
			int cur = num[0];
			if (cur == target) {
				vector<int> tmp;
				tmp.push_back(cur);
				ret.push_back(tmp);
			}

			num.erase(num.begin());

			vector<vector<int> > ret_tmp = combinationSum2(num, target - cur);
			for (int i = 0; i < ret_tmp.size(); ++i) {
				vector<int> tmp = ret_tmp[i];
				tmp.insert(tmp.begin(), cur);
				ret.push_back(tmp);
			}
			int count = 0;
			while(cur == num[0] && num.size() > 0) { //if at the end of the vector, this time the size if vector is 0 and we access into the vector then will cause seg fault
				num.erase(num.begin());
				++count;
			}
		
			ret_tmp = combinationSum2(num, target);
			for (int i = 0; i < ret_tmp.size(); ++i) {
				ret.push_back(ret_tmp[i]);
			}

			//num.insert(num.begin(), cur);
			for (int i = 0; i <= count; ++i) {
				num.insert(num.begin(),cur);
			}
			return ret;
		}
};

int main(int argc, char **argv) {
	int a[] = {10,1,2,7,1,6,5};
	vector<int> test(a, a + 7);
	Solution sol;
	vector<vector<int> > res = sol.combinationSum2(test, 8);
	for (int i = 0; i < res.size(); ++i) {
			vector<int> tmp = res[i];
			for (int j = 0; j < tmp.size(); ++j) {
				cout << tmp[j] << " ";
			}
			cout << endl;
	}
	return 1;
}
