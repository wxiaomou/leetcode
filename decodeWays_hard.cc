#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (!n) return 0;
        int ref[n];
        for (int i = 0; i < n; i++) ref[i] = -1;
        return recur(s, 0, n, ref);
    }
    
    int recur(string S, int i, int n, int ref[]) {
        if (i > n) return 0;
        if (i == n) return 1;
        if (S[i] == '0') {
            ref[i] = 0;
            return 0;
        }
        if (ref[i] != -1) return ref[i];
        if ( i < n - 1 && (S[i] < '2' || (S[i] == '2' && S[i + 1] <= '6')) ) 
            ref[i] = recur(S, i + 1, n, ref) + recur(S, i + 2, n, ref);
        else 
            ref[i] = recur(S, i + 1, n, ref);
        return ref[i];
    }


    
    //----------------------------//
	 int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!s.length()) return 0;
        int n = s.length();
        int ref[n];
        for (int i = 0; i < n; i++)
            ref[i] = -1;
        doRec(s, ref, 0, n);
        return ref[0];
    }
    int doRec(string s, int ref[], int i, const int& n) {
        if (i >= n)
				return 0;
        if (i == n - 1 && s[i] != '0') {
			ref[i] = 1;
			return ref[i];
		}
		if (s[i] == '0') {
			ref[i] = 0;
			return ref[i];
		}
        if (ref[i] != -1) return ref[i];
        if (s.length() == 1) {
            ref[i] = 1;
            return 1;
        }
        int ret = 0;
        int fix = n - i == 2 ? 1: 0;// eg 11123 so if we do not have the fix;  when i == 3, tmp is 23 which will go to 
        			    // the first block, then the doRec(s, ref, i + 2, n) will return 0, so we will miss
        			    // one here.
        int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (tmp <= 26) {
            ret = doRec(s, ref, i + 2, n) + doRec(s, ref, i + 1, n) + fix;
        } else {
            ret = doRec(s, ref, i + 1, n);
        }
        ref[i] = ret;
        return ret;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	string input("12");
	cout << sol.numDecodings(input) << endl;
	return 1;
}
