#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0|| s.size() % 2)
			return false;
		int left1 = 0;
		int left2 = 0;
		int left3 = 0;
		int right1 = 0;
		int right2 = 0;
		int right3 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				left1++;
				if (s[i + 1] == '}' || s[i + 1] == ']')
					return false;
			}
			else if (s[i] == '{') {
				left2++;
				if (s[i + 1] == ')' || s[i + 1] == ']')
					return false;
			}
			else if (s[i] == '[') {
				left3++;
				if (s[i + 1] == '}' || s[i + 1] == ')')
					return false;
			} else if (s[i] == ')')
				right1++;
			else if (s[i] == '}')
				right2++;
			else
				right3++;

			if(right1 > left1 || right2 > left2 || right3 > left3)
				return false;
		}
		if (right1 != left1 || right2 != left2 || right3 != left3)
			return false;

		return true;
		}
};

int main(int argc, char **argv) {
	return 0;
}
