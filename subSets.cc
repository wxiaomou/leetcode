#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > res;
		if (S.size() == 0) {
			vector<int> e;
			res.push_back(e);
			return res;
		}
		int tmp = S[0];
		S.erase(S.begin());
		res = subsets(S);
		vector<vector<int> > res1 = res;
		for (int i = 0; i < res1.size(); i++) {
			res1[i].insert(res1[i].begin(), tmp);
			sort(res1[i].begin(), res1[i].end());
		}
		res.insert(res.end(), res1.begin(), res1.end());
		return res;
	}
};

int main(int argc, char **argv) {
	return 0;
}
