#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	//better solution
	 int romanToInt(string s) {
        int n = s.length();
        if (!n) return 0;
        int i = 0;
        int ret = 0;
        while (i < n) {
            if (s[i] == 'M') {
                ret += 1000;
            } else if (s[i] == 'D') {
                ret += 500;
            } else if (s[i] == 'C') {
                ret += 100;
            } else if (s[i] == 'L') {
                ret += 50;
            } else if (s[i] == 'X') {
                ret += 10;
            } else if (s[i] == 'V') {
                ret += 5;
            } else if (s[i] == 'I') {
                ret += 1;
            }
            i++;
        }
        i--;
        while (i >= 0) {
            if (i > 0) {
               if ((s[i] == 'X' || s[i] == 'V') && s[i - 1] == 'I') {
                    ret -= 2;
                } else if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X') {
                    ret -= 20;
                } else if ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C') {
                    ret -= 200;
                }
            }
            i--;
        }
        return ret;
    }
	/*int romanToInt(string s) {
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
	}*/
};

int main (int argc, char **argv) {
	return 0;
}
