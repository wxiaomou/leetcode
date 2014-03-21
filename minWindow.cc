#include <iostream>
#include <string>
#include <stddef.h>
#include <limits.h>
using namespace std;

class Solution {
public:
	 string minWindow(string S, string T) {
        int m = S.length(), n = T.length();
        if (m < n) return "";
        int cnt = 0, start = -1, begin = 0, end = m - 1;
        unordered_map<char, int> need;
        unordered_map<char, int> have;
        for (int i = 0; i < n; i++)  {
            if (need.count(T[i]) == 0)
                need[T[i]] = 1;
            else
                need[T[i]] ++;
        }
        
        for (int i = 0; i < m; i++) {
            if (need.count(S[i]) > 0) {
                if (start < 0) start = i;
                
                if (have.count(S[i]) == 0)
                    have[S[i]] = 1;
                else
                    have[S[i]]++;
                    
                if (have[S[i]] <= need[S[i]]) cnt++;
                
                if (cnt == n) {
                    int j = start;
                    while (j <= i) {
                        if (need.count(S[j]) > 0) {
                            if (have[S[j]] > need[S[j]]) {
                                have[S[j]]--;
                            } else if (have[S[j]] == need[S[j]]) {
                                start = j;
                                break;
                            }
                        }
                        j++;
                    }
                    if (i - start < end - begin) {
                        begin = start;
                        end = i;
                    } 
                }
            }
        }
        if (cnt == n)
            return S.substr(begin, end - begin + 1);
        return "";
    }

	//-----------------------------------------------//
	string minWindow(string S, string T) {
        int n = S.length(), m = T.length();
        if (n < m) return "";
        int start = -1, len = n, total = 0;
        queue<int> q;
        unordered_map<char, int> need;
        unordered_map<char, int> have;
        for (int i = 0; i < m; i++) need[T[i]]++;
        for (int i = 0; i < n; i++) {
            if (need.count(S[i]) > 0) {
                if (start == -1) {
                    start = i;
                }
                q.push(i);
                have[S[i]] ++;
                if (have[S[i]] <= need[S[i]]) total++;
                if (total == m) {
                    len = min(i - start + 1, len);
                    while (have[S[q.front()]] > need[S[q.front()]]) {
                        have[S[q.front()]]--;
                        q.pop();
                        if (i - q.front() + 1 < len) {
                            start = q.front();
                            len = i - q.front() + 1;
                        }
                    }
                }
            }
        }
        if (total < m) return "";
        return S.substr(start, len);
    }
	//-----------------------------//
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
