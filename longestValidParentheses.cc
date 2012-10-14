#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
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
