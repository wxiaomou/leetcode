#include <iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x / 10 == 0)
			return x;

		int base = 10;
		int ret = 0;
		while (x) {
			int tmp = x % base;
			ret *= 10;
			ret += tmp;
			x /= 10;
		}

		return ret;
	}
};

int main (int argc, char **argv) {
	return 0;
}
