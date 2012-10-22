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
        
};

int main (int argc, char **argv) {
	return 0;
}
