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
	/*
	string convert(string s, int nRows) {
        if (nRows < 2) return s;
        int n = s.length();
        string ret = "";
        for ( auto i = 0; i < nRows; ++i ) {
            int j = i;
            while (j < n) {
                if (i == 0 || i == nRows - 1) {
                    ret += s[j];
                    j += nRows + nRows - 2;
                } else {
                    ret += s[j];
                    j += (nRows - 1 - i) * 2;
                    if (j < n) {
                        ret += s[j];
                        j += i * 2;
                    }
                }
            }
        }
        return ret;
    }
	*/
};

int main(int argc, char **argv) {
	return 0;
}

