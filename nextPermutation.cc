#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		 if (!num.size())
    		return;

		int pos = num.size() - 1;

		while (pos > 0 && num[pos - 1] >= num[pos]) pos--;
		pos--;

		if (pos >= 0) {
			int k = num.size() - 1;
			while (num[k] <= num[pos]) k--;
			int tmp = num[pos];
			num[pos] = num[k];
			num[k] = tmp;
		}
		sort(num.begin() + pos + 1, num.end());
	}
	//--------------------------------------------//
	 void nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return;
        int i = n - 1;
        while (i > 0) {
            if (num[i] <= num[i - 1]) {
                i--;
            } else {
                int ind = i;
                for (int j = i; j < n; ++j) {
                    if (num[j] > num[i - 1])
                        ind = j;
                }
                int tmp = num[i - 1];
                num[i - 1] = num[ind];
                num[ind] = tmp;
                sort(num.begin() + i, num.end());
                return;
            }
        }
        sort(num.begin(), num.end());
        return;
    }
};

int main (int argc, char **argv) {
	return 0;
}
