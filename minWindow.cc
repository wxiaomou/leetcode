#include <iostream>
#include <string>
#include <stddef.h>
#include <limits.h>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		        int need[256];
    	int have[256] = {0};

		int begin = 0;
		int end = 0;

		for (int i = 0; i < 256; ++i) need[i] = -1;
		for (int i = 0; i < T.size(); ++i) {
			if (need[T[i]] == -1)
				need[T[i]] = 1;
			else
				need[T[i]] ++;
		}

		int count = 0;
		int length = INT_MAX;
		int start = 0;

		while (end < S.size()) {
			if (need[S[end]] == -1) {
				end++;
				continue;
			}
			have[S[end]]++;
			if (have[S[end]] <= need[S[end]])
				count++;
			if (count == T.length()) {
				while (need[S[begin]] == -1 || have[S[begin]] > need[S[begin]]) {
					if (have[S[begin]] > need[S[begin]])
						have[S[begin]]--;
					begin++;
				}
				if (end - begin + 1 < length) {
					start = begin;
					length = end - begin + 1;
				}
				
			}
        	end++;		
		}

		return length <= S.length() ? S.substr(start, length) : "";
	}

};

int main (int argc, char **argv) {
	Solution sol;
	cout << sol.minWindow("bdab", "ab") << endl;
	return 0;
}
