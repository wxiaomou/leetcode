#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string ret = "";
		if (!strs.size())
			return ret;
		int i = 0;
		while(true) {
			string tmp;
			if (strs[0].size() <= i)
				break;
			else
				tmp = strs[0].at(i);
			int j;
			for (j = 1; j < strs.size(); ++j) {
				if (strs[j].size() <= i)
					break;
				else if (strs[j].at(i) != *tmp.c_str())
					break;
			}
			if (j == strs.size())
				ret += tmp;
			else 
				break;
			i++;
		}
		return ret;
	}
};

int main(int argc, char **argv) {
	vector<string> strs;
	strs.push_back("abcd");
	strs.push_back("abc");
	Solution sol;
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
