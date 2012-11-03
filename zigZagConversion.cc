#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	string convert(string s, int nRows) {
		string ret;
		for (int i= 0; i < nRows; i++) {
			for (int j = 0, k = i; k < s.length(); j ++) {
				ret += s[k];
				if (nRows == 1)
					k += 1;
				else if (i == 0 || i == nRows - 1)
					k += 2 * (nRows - 1);
				else
					k = ((j & 1) ? (j + 1) * (nRows - 1) + i : k + 2 * (nRows - 1 - i));// when j = 0 is not the first char, it's the second char for this line, because 
																					// we are computing the index for the next element. So using even j to compute odd index 
																					// elements.
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {
	return 0;
}

