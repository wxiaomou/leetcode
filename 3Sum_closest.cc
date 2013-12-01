#include<iostream>
#include<vector>
#include<algorithm>
#include<stddef.h>
#include<math.h>
using namespace std;

class Solution {
	public:
		int threeSum(vector<int> &num, int target) { // Attention when vec def >> should be > > !!!!!!!!!!!!111
			if (num.size() < 3)
				return 0;
			sort(num.begin(), num.end());
			int ret = num[num.size() - 1] + num[0] + num[1];//!!!important start value!!!
			int diff = ret - target;
			for (int i = 0; i < num.size(); ++i) { 
				int stable = num[i];
				int k = num.size() - 1;
				int j = i + 1;
				while (j < k) {
					if (((num[j] + num[k] + num[i] - target) > 0) && (num[i] + num[j] + num[k] - target>= abs(diff)))
						k--;
					else if (((num[i] + num[j] + num[k] - target) < 0) && (abs(num[i] + num[j] + num[k] - target) >= abs(diff)))
						j++;
					else {
						ret = num[i] + num[j] + num[k];
						diff = ret - target;
						if (diff > 0)
							k--;
						else 
							j++;
					}
				}
			}
			return ret;
		}
};


int main(int argc, char **argv) {
	vector<int> num; 
	num.push_back(1);
//	num.push_back(-1);
	num.push_back(1);
//	num.push_back(0);
	num.push_back(1);
	num.push_back(0);
/*
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
*/
	Solution tmp;
	cout << tmp.threeSum(num, -100) << endl;
}
