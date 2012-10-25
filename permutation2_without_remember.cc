#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > res;
	vector<int> tmp;
	vector<vector<int> > permuteUnique(vector<int> &num) {
		if (!num.size())
			return res;
		tmp = num;
		sort(tmp.begin(), tmp.end());
		recursion(0);
		return res;
	}

	void recursion(int n) {
		if (n == tmp.size() - 1) {
			res.push_back(tmp);
			return;
		}

		for (int i = tmp.size() - 1; i >= n; i--) {//i < tmp.size(); i++) {
			swap(tmp[n], tmp[i]);
			recursion(n + 1);
			swap(tmp[n], tmp[i]);
			while (tmp[i + 1] == tmp[i]) i--;
		}

		return;
	}

	void swap(int &a, int &b) {
		int a1 = b;
		b = a;
		a = a1;
		return;
	}
};

int main(int argc, char **argv) {
	Solution sol;
	int a[] = {1, 2};
	vector<int> test(a, a + 2);

	vector<vector<int> > res = sol.permuteUnique(test);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) 
			cout << res[i][j] << " ";
		cout << endl;

	}
	return 0; 
}
