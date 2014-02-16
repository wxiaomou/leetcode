#include<iostream>
#include<vector>
#include<algorithm>
#include<stddef.h>
using namespace std;

class Solution {
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) { 
			vector<vector<int> > ret;
			if (num.size() < 4)
				return ret;
			sort(num.begin(), num.end());
			for (int p = 0; p < num.size(); ++p) {
				for (int i = p + 1; i < num.size(); ++i) { 
					int stable = num[i];
					int k = num.size() - 1;
					int j = i + 1;
					while (j < k) {
						if (num[p] + num[j] + num[k] + num[i] > target)
							k--;
						else if (num[p] + num[i] + num[j] + num[k] < target)
							j++;
						else {
							vector<int> tmp;
							tmp.push_back(num[p]);
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
				while(num[p] == num[p + 1]) p++;
			}
			return ret;
		}
		
		/*
		vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        if (n < 4) return vector<vector<int>>();
        sort(num.begin(), num.end());
        vector<vector<int>> ret;
        int i = 0;
        while (i < n - 3) {
            int first = num[i];
            int j = i + 1;
            while (j < n - 2) {
                int sec = num[j];
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    int third = num[k];
                    int four = num[l];
                    if (first + sec + third + four == target) {
                        vector<int> tmp;
                        tmp.push_back(first);
                        tmp.push_back(sec);
                        tmp.push_back(third);
                        tmp.push_back(four);
                        ret.push_back(tmp);
                        while (k < n && num[k] == third) k++;
                        while (l >= 0 && num[l] == four) l--;
                    } else if (first + sec + third + four > target) {
                        while (k < n && num[l] == four) l--;
                    } else {
                        while (l >= 0 && num[k] == third) k++;
                    }
                }
                while (j < n - 2 && num[j] == sec) j++;
            }
            while (i < n - 3 && num[i] == first) i++;
        }
        return ret;
    }
		*/
};


int main(int argc, char **argv) {
	vector<int> num; 
	num.push_back(-5);
	num.push_back(-5);
	num.push_back(-3);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(5);
	num.push_back(0);
	num.push_back(4);
/*	
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
*/
	Solution tmp;
	vector<vector<int> > ret = tmp.fourSum(num, -1);
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
