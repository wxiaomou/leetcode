#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
        int len = 0;
        int n = s.length();
        int j = 0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                left--;
                if (left < 0) {
                    left = 0;
                    j = i + 1;
                }
                if (left == 0) len = max(len, i - j + 1);
            } else if (s[i] == '(') {
                left ++;
            }
        }
        left = 0;
        j = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left--;
                if (left < 0) {
                    left = 0;
                    j = i - 1;
                }
                if (left == 0) len = max(len, j - i + 1);
            } else if (s[i] == ')') {
                left ++;
            }
        }
        return len;
    }
	//--------------------------------------//
	int longestValidParentheses(string s) {
        int n = s.length();
        if (n < 2) return 0;
        int ret = 0;
        int cur = 0;
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (start < 0) start = i;
                cur++;
            } else {
                cur--;
            }
            
            if (cur == 0) {
                ret = max(ret, i - start + 1);
            } else if (cur < 0) {
                start = -1;
                cur = 0;
            }
        }
        cur = 0;
        start = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                if (start < 0) start = i;
                cur++;
            } else {
                cur--;
            }
            
            if (cur == 0) {
                ret = max(ret, start - i + 1);
            } else if (cur < 0) {
                start = -1;
                cur = 0;
            }
        }
        return ret;
    }

	//--------------------------------------//
	int longestValidParentheses(string s) {
		if (2 > s.size())
			return 0;

		int cur_sum = 0;
		int cur_length = 0;
		int m_max = 0;

		for (int i = 0; i < s.size(); ++i) {
			cur_length++;
			if ('(' == s[i])
				cur_sum++;
			else
				cur_sum--;

			if (cur_sum == 0) {
				m_max = max(m_max, cur_length);
			} else if (cur_sum < 0){
				cur_sum = 0;
				cur_length = 0;
			}
		}

		cur_sum = 0;
		cur_length = 0;
		
		for (int i = s.size() - 1; i >= 0; --i) {
			cur_length++;
			if (')' == s[i])
				cur_sum++;
			else
				cur_sum--;

			if (cur_sum == 0) {
				m_max = max(m_max, cur_length);
			} else if (cur_sum < 0){
				cur_sum = 0;
				cur_length = 0;
			}
		}
		return m_max;
	}
};

int main(int argc, char **argv) {
	Solution sol;
	cout << sol.longestValidParentheses("(()") << endl;

}
