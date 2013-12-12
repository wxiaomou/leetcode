#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
        if (!x) return true;
        if (x < 0) return false;
        x = abs(x);
        int base = 1;
        while (x / base >= 10) base *= 10; // !!! use '>=' not '>' 
        int base1 = 1;
        while (base1 <= base) {
            int right = x / base1;
            right %= 10;
            int left = x / base;
            left %= 10;
            if (left != right) return false;
            base1 *= 10;
            base /= 10;
        }
        return true;
    }
	/*bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if ((x / 10) == 0)
			return true;

		int a = x;
		int div = 1;
		int count = 0;
		while (a / div && div * 10 > div) {
			div *= 10;
			//cout << "div " << div << endl;
			count++;
		}
		cout << count << endl;
		int i = 0;
		while (i < (count / 2)) {
			int left = (a / int(pow(10, count - i - 1))) % 10;
			int right = (a / int(pow(10, i))) % 10;
			cout << "left:" << left << "-right:" << right << endl;
			if (left == right)
				i++;
			else 
				return false;
		}
		return true;
	}*/
};

int main(int argc, char **argv) {
	Solution sol;
	if (sol.isPalindrome(2147447412))
		cout << "true" << endl;
	else 
		cout << "false" << endl;
	return 0;
}
