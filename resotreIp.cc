#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	class Solution {
public:
 vector<string> restoreIpAddresses(string s) {
    	vector<string> res;
		if (s.length() > 12 || s.length() < 4)
			return res;
		string tmp("");
		recursion(s, tmp, 0, 0, res);
		return res;
	}

	void recursion (string &s, string tmp, int begin, int level, vector<string> &res) {
		if 	(begin == s.length() && level == 4) {
			res.push_back(tmp);
            return;
		}
		int x = 0;
		for (int i = begin; i < begin + 4 && i < s.size(); ++i) {
			x = x * 10 + s[i] - '0';
			string str = tmp;

			if (x > 255 || x < 0)
				break;
			if (level > 0)
				str += ".";

			string st = s.substr(begin, i - begin + 1);
			//if (st.length() > 1 || st[0] == '0')
			//	break;
			str += st;
			recursion(s, str, i + 1, level + 1, res);
            if (x == 0) break;// for case 0000!!!
		}
		return;
	}

};
};

int main (int argc, char **argv) {
	return 0;
}
