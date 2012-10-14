#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	 string longestPalindrome(string s) {
    	if(s.length() <= 1)
			return s;
		int len = 0;
		string ret;
		for (int i = 0; i < s.length(); ++i) {
			string tmp = length(s, i);
			//cout << tmp << endl;
			if (tmp.length() > len) {
				len = tmp.length();
				ret = tmp;
			}

		}

		return ret;
	}

	string length(string s, int index) {
		int i;
		for (i = 0; index - i >= 0  && (index + i) < s.length(); ++i) {
			if (s[index - i] != s[index + i])
				break;
		}
		string res1;
		if ( 2 * i - 1 >= 0)
			res1 = s.substr(index - i + 1, 2 * i - 1);

		//cout << "index:" << index << "i " << i << " " << res1 << endl;
		// even.
		i = 0;
		while (index - i >= 0 && index + i < s.length()) {
			if (s[index - i] != s[index + i + 1]) 
				break;
			i++;
		}
	//	i--;
		string res2 = s.substr(index - i + 1, 2 * i);
		//cout << res2 << endl;

		
};

int main(int argc, char **argv) {
	Solution sol;
//	cout << sol.longestPalindrome("babcbabcbaccba") << endl;
	cout << sol.longestPalindrome("abb") << endl;
//	string a("bb");
//	cout << a.substr(0, 1) << endl;
}
