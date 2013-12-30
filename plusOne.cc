#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	 vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        if (!n) return digits;
        int adv = 1;
        for (int i = n - 1; i >= 0; --i) {
            int tmp = digits[i] + adv;
            if (tmp >= 10) {
                adv = 1;
            } else {
                adv = 0;
            }
            digits[i] = tmp % 10;
        }
        if (adv) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

	/*vector<int> plusOne(vector<int> &digits) {
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
	}*/
};

int main (int argc, char **argv) {
	return 0;
}
