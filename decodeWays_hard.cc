#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
		int n;
		int* loc;
		string str;
    int numDecodings(string s) {
			if (s.length() == 0)
				return 0;
			n = s.length();
			loc = new int(n);
			str = s;
			for (int i = 0; i < n; ++i) loc[i] = -1;
			int ret = recursion(0);
			delete []loc;
			return ret;

    }

		int recursion(int i) {
			if (i >= n)
				return 1;
			if (loc[i] != -1) 
				return loc[i];
			if (i == n - 1) {
				loc[i] = 1;
				return loc[i];
			}
			if (str[i] == '0') {
				loc[i] = 0;
				return loc[i];
			}
			int tmp = (str[i] - '0') * 10 + (str[i + 1] - '0');
			if (tmp > 26) {
					loc[i] = recursion(i + 1);
			} else {
					loc[i] = recursion(i + 1) + recursion(i + 2);
			}
			return loc[i];
		}
};


int main(int argc, char** argv) {
	Solution sol;
	string input("12");
	cout << sol.numDecodings(input) << endl;
	return 1;
}
