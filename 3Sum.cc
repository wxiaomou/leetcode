#include<iostream>
#include<vector>
#include<algorithm>
#include<stddef.h>
using namespace std;

class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int n = num.size();
        if (n < 3) return vector<vector<int>>();
        vector<vector<int>> ret;
        for (int i = 0; i + 2 < n;) {
            int first = num[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (first + num[j] + num[k] == 0) {
                    vector<int> tmp;
                    int second = num[j];
                    int third = num[k];
                    tmp.push_back(first);
                    tmp.push_back(second);
                    tmp.push_back(third);
                    ret.push_back(tmp);
                    while (num[j] == second) j++;
                    while (num[k] == third) k--;
                } else if (first + num[j] + num[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            while (i + 2 < n && num[i] == first) i++;
        }
        return ret;
    }
		/*vector<vector<int> > threeSum(vector<int> &num) { 
			vector<vector<int> > ret;
			if (num.size() == 0)
				return ret;
			sort(num.begin(), num.end());
			for (int i = 0; i < num.size(); ++i) { 
				int stable = num[i];
				int k = num.size() - 1;
				int j = i + 1;
				while (j < k) {
					if (num[j] + num[k] + num[i] > 0)
						k--;
					else if (num[i] + num[j] + num[k] < 0)
						j++;
					else {
						vector<int> tmp;
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[k]);
						ret.push_back(tmp);
						j++;
						k--;
						while(num[j] == num[j - 1]) j++;
						while(num[k] == num[k + 1]) k--;
					}
					while(num[i] == num[i + 1]) i++;
				}
			}
			return ret;
		}*/
};


int main(int argc, char **argv) {
	vector<int> num; 
	num.push_back(-1);
	num.push_back(-1);
	num.push_back(1);
	num.push_back(0);
	num.push_back(2);
	num.push_back(-4);
	
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);

	Solution tmp;
	vector<vector<int> > ret = tmp.threeSum(num);
	vector<vector<int> >::iterator it = ret.begin();
	while (it != ret.end()) {
		vector<int>::iterator it1 = (*it).begin();
		while (it1 != (*it).end()) {
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		++it;
	}
}
