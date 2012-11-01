#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
	    vector<vector<int> > res;
    	 sort(S.begin(), S.end());
    	if (S.size() == 0) {
			vector<int> e;
			res.push_back(e);
			return res;
		}
		int tmp = S[0];
		vector<int> t(1, tmp);
        S.erase(S.begin());

		while (!S.empty() && tmp == S[0]) {
			t.push_back(S[0]);
            S.erase(S.begin());
		}
			
		res = subsetsWithDup(S);
        vector<vector<int> > res1 = res;
		for (int j = 1; j <= t.size(); j++) {
		     vector<vector<int> > res2 = res1;
			for (int i = 0; i < res2.size(); i++) {
				res2[i].insert(res2[i].begin(), t.begin(), t.begin() + j);
				sort(res2[i].begin(), res2[i].end());
			}
			res.insert(res.end(), res2.begin(), res2.end());
		}
		return res;
	}
};

int main(int argc, char **) {
	return 0;
}
