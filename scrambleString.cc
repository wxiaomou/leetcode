#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		int n = s1.length();
    	// base case.
		if (n == 1)
			return (s1.compare(s2) == 0);

		// iterate all possible partitions in this level.
		for (int i = 1; i <= n / 2; i++) {
			string x1 = s1.substr(0, i); string y1 = s1.substr(i);
			string x2 = s2.substr(0, i); string y2 = s2.substr(i);
			string a1 = s1.substr(0, n - i); string b1 = s1.substr(n - i);
			string a2 = s2.substr(0, n - i); string b2 = s2.substr(n - i);
			bool r1 = isScramble(x1, x2) && isScramble(y1, y2);
			if (r1) return true;
			bool r2 = isScramble(x1, b2) && isScramble(y1, a2);
			if (r2) return true;
			bool r3 = isScramble(x2, b1) && isScramble(y2, a1);
			if (r3) return true;
			bool r4 = isScramble(a1, a2) && isScramble(b1, b2);
			if (r4) return true;

		}
		return false;
	}
};

int main(int argc, char **argv) {
	return 0;
}
