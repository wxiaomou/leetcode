#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	// ip addr cannot be 0xx, so the only way is set the bit to be 0, so when we met tmp = "0" , we should break and not add more digit in this section
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
		for (int i = begin; i < begin + 3 && i < s.size(); ++i) {
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
      		if (x == 0) break;// for case 0000!!! 101023 '0' will be only recurse itself  won't be case '01' 
		}
		return;
	}

// Mathod 2
/*
	 vector<string> restoreIpAddresses(string s) {
	 	vector<string> ret;
		if (s.length() > 12 || s.length() < 4) return ret;
		ret = _restore(s, 0);
        }
	vector<string> _restore(string s, const int k) {
		vector<string> ret;
		if (k >= 4 || s.size() == 0) return ret;
		if (k == 3 && atoi(s.c_str()) <= 255) {
  			if (s.size() > 1 && s[0] == '0') return ret;
	                ret.push_back(s);
			return ret;
			
		}				
		int n  = s.size();
		for (int i = 0; i < n && i < 3; i++) {
			int x = atoi(s.substr(0, i + 1).c_str());
			if (x > 255)
				break;

			vector<string> tmp = _restore(s.substr(i + 1), k + 1);
			for (int j = 0; j < tmp.size(); j++) {
				char *st = itoa(x);
				string s1 = string(st);
				tmp[j] = s1 + "." + tmp[j];
			}
			ret.insert(ret.end(), tmp.begin(), tmp.end());
			if (x == 0) break;
		}
		return ret;

	}

 * /
};


int main (int argc, char **argv) {
	return 0;
}
