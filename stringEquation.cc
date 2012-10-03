#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int stringEquation(string equal) {
		if (equal.length() < 3)
			return 0;
		vector<char> Operator;
		vector<int> num;
		for (int i = 0; i < equal.length(); ++i) {
			if (equal[i] == '+' || equal[i] == '-' ||
					equal[i] == '*' || equal[i] == '/') {
				Operator.push_back(equal[i]);
			} else {
				num.push_back(equal[i] - '0');
			}
		}

		for(int i = 0; i < Operator.size(); ++i) {
			if (Operator[i] == '*') {
				num[i + 1] = num[i] * num[i + 1];
				num[i] = 0;
				Operator[i] = '+';
			} else if (Operator[i] == '/') {
				num[i + 1] = num[i] / num[i + 1];
				num[i] = 0;
				Operator[i] = '+';
			}
		}
		int ret = num[0];
		for (int i = 0; i < Operator.size(); ++i) {
			if (Operator[i] == '+') 
				ret += num[i + 1];
			if (Operator[i] == '-')
				ret -= num[i + 1];
		}
		return ret;
	}

};

int main(int argc, char **argv) {
	Solution sol;
	cout << sol.stringEquation("3+5*2-6") << endl;
}
