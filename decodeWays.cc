#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	int *m;
	string str;
	int numDecodings(string s) {
		m = new int[s.length()];// new int[]!!!!!!!!!!!!!!!!!!!!11
		for (int i = 0; i < s.length(); ++i) m[i] = -1;
		if (s.length() == 0)
			return 0;
		str = s;
		int n = s.length();
		dp(0, n);
		int ret = m[0];
		delete []m;
		return ret;
	}	
	
	int dp(int index, int n) {
		if (index >= n) {
			return 1;
		}

		if (m[index] != -1) return m[index];
		if (str[index] == '0') {
			m[index] = 0;
			return m[index];
		}

		if (index == n - 1) {
			m[index] = 1;
			return m[index];
		}
		int tmp = (str[index] - '0') * 10 + (str[index + 1] - '0');

		if (tmp > 26) {
				m[index] = dp(index + 1, n);
		} else {
				m[index] =  dp(index + 1, n) + dp(index + 2, n);
		} 

		return m[index];


	}

};

int main(int argc, char **argv) {
	Solution sol;
	cout << sol.numDecodings("1029") << endl;
	return 1;

}
