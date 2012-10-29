#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	  vector<int> searchRange(int A[], int n, int target) {
    	vector<int> res;
		if (target < A[0] || target > A[n - 1]) {
    	    res.push_back(-1);
            res.push_back(-1);
            return res;
		}

		doSearch(A, 0, n - 1, target, res);
		return res;
	}

	void doSearch(int A[], int start, int end, const int target, vector<int> &res) {
		if (start > end) {
            res.push_back(-1);
            res.push_back(-1);
            return;
		}

		int i = (start + end) / 2;
		if (A[i] == target) {
			int j = i;
			while (A[j] == target && j >= start) j--;
            
			res.push_back(++j);
			j = i;
			while (A[j] == target && j <= end) j++;
			res.push_back(--j);
		} else if (A[i] > target) {
			doSearch(A, start, end - 1, target, res);
		} else {
			doSearch(A, i + 1, end, target, res);
		}
		return;
	}
};

int main(int argc, char **argv) {
	return 0;
}
