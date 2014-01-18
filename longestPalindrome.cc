#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
        int n = s.size();
        if (!n) return "";
        string ret = "";
        int len = 0;
        for (int i = 0; i < n; i++) {
            string tmp;
            int tmp_len = _length(i, s, tmp);
            if (tmp_len > len)  {
                ret = tmp;
                len = tmp_len;
            }
        }
        return ret;
    }
    
    int _length(int i, const string s, string &tmp) {
        int j = 1;
        int len = 1;
        while (i - j >= 0 && i + j < s.size()) {
            if (s[i - j] != s[i + j]) break;
            len += 2;
            j++;
        }
        tmp = s.substr(i - j + 1, len);
        j = i + 1;
        int len1 = 0;
        while (i >= 0 && j < s.size()) {
            if (s[i] != s[j]) break;
            len1 += 2;
            j++;
            i--;
        }
        if (len1 > len) {
            tmp = s.substr(i + 1, len1);
            return len1;
        }
        return len;
    } 
	//----------------------------------------//
	string longestPalindrome(string s) {
            int n = s.length();
            if (!n) return s;
            string ret;return res1.length() > res2.length() ? res1 : res2;
            for ( auto i = 0; i < n; ++i ) {
                string tmp = _length(s, i);
                ret = ret.length() > tmp.length() ? ret : tmp;
            }
            return ret;
        }

        string _length(string &s, int index) {
             int i = 0;
             // odd
             while (index - i >= 0 && index + i < s.length()) {
                 if (s[index - i] != s[index + i])
                    break;
                 i++;
             }
             
             //if ( !(index - i >= 0 && index + i < s.length()) ) i--;
             i--;
             string res1 = s.substr(index - i, 2 * i + 1);
             
             i = 0;
             while (index - i >= 0 && index + i + 1 < s.length()) {
                 if (s[index - i] != s[index + i + 1])
                    break;
                 i++;
             }
             
             //if ( !(index - i >= 0 && index + i + 1 < s.length()) ) i--;
             i--;
             string res2 = s.substr(index - i, (i + 1) * 2);
             
             
             
        }
	 /*string longestPalindrome(string s) {
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
		
		return res1.length() > res2.length() ? res1 : res2;
	}	*/
};

int main(int argc, char **argv) {
	Solution sol;
//	cout << sol.longestPalindrome("babcbabcbaccba") << endl;
	cout << sol.longestPalindrome("abb") << endl;
//	string a("bb");
//	cout << a.substr(0, 1) << endl;
}
