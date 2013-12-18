#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
        if (!strs.size()) return "";
        int i = 0;
        string ret = "";
        while (true) {
            if (i >= strs[0].size())
                break;
            char ref;
            ref = strs[0].at(i);
            int j;
            for (j = 1; j < strs.size(); ++j) {
                if (strs[j].size() <= i)
                    break;
                if (ref != strs[j][i])
                    break;
            }
            if (j == strs.size())
                ret += ref;
            else
                break;
            i++;
        }
        return ret;
    }
	/*string longestCommonPrefix(vector<string> &strs) {
		string ret = "";
		if (!strs.size())
			return ret;
		int i = 0;
		while(true) {
			string tmp; //string tmp = strs[0].at(i); won't work
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
	}*/
};

int main(int argc, char **argv) {
	vector<string> strs;
	strs.push_back("abcd");
	strs.push_back("abc");
	Solution sol;
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
