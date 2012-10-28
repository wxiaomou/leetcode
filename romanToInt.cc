#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		if (s.length() == 0)
			return 0;
		if (s[0] == 'M') {
			return 1000 + romanToInt(s.substr(1));
		} else if (s[0] == 'D') {
			if (s[1] != 'M')
				return 500 + romanToInt(s.substr(1));
			else
				return -500 + romanToInt(s.substr(1));
		} else if (s[0] == 'C') {
			if (s[1] != 'M' && s[1] != 'D')
				return 100 + romanToInt(s.substr(1));
			else 
				return -100 + romanToInt(s.substr(1));
		} else if (s[0] == 'L') {
			if (s[1] != 'M' && s[1] != 'D' && s[1] != 'C')
				return 50 + romanToInt(s.substr(1));
			else
				return -50 + romanToInt(s.substr(1));
		} else if (s[0] == 'X') {
			if (s[1] != 'M' && s[1] != 'D' && s[1] != 'C' && s[1] != 'L')
				return 10 + romanToInt(s.substr(1));
			else
				return -10 + romanToInt(s.substr(1));
		} else if (s[0] == 'V') {
			if (s[1] != 'M' && s[1] != 'D' && s[1] != 'C' && s[1] != 'L' && s[1] != 'X')
				return 5 + romanToInt(s.substr(1));
			else
				return -5 + romanToInt(s.substr(1));
		} else {
			if (s[1] != 'M' && s[1] != 'D' && s[1] != 'C' && s[1] != 'L' && s[1] != 'X' && s[1] != 'V')
				return 1 + romanToInt(s.substr(1));
			else
				return -1 + romanToInt(s.substr(1));
		}
	}
};

int main (int argc, char **argv) {
	return 0;
}
