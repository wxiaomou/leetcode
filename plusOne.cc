#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		if (!digits.size())
			return digits;

		int carry = 0;
		carry = carry + digits[digits.size() - 1] + 1;
		digits[digits.size() - 1] = carry % 10;
		carry /= 10;
		for (int i = digits.size() - 2; i >=0; i--) {
			carry = carry + digits[i];
			digits[i] = carry % 10;
			carry /= 10;
		//	if (!carry)
		//		break;
		}

		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main (int argc, char **argv) {
	return 0;
}
