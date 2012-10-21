#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
    		return "0";
		
		vector<int> res(num1.size() + num2.size(), 0);

		
		for (int i = 0; i < num1.size(); ++i) {
            int carry = 0;
			for (int j = 0; j < num2.size(); ++j) {
				int d1 = num1[num1.size() - i - 1] - '0';
				int d2 = num2[num2.size() - j - 1] - '0';

				carry = carry + res[i + j] + d1 * d2;
				res[i + j] = carry % 10;
				carry /= 10;
			}
			res[i + num2.size()] = carry;
		}

		int p = res.size() - 1;
		string ret;
		while (res[p] == 0 && p > 0) p--;
    while (p >= 0) ret += char (res[p--] + '0'); 
		
		return ret;
	}

};

int main (int argc, char **argv) {
	return 0;
}
