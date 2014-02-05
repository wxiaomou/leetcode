#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (!n) return true;
        return Scramble(s1, s2);
    }
    bool Scramble(string &s1, string &s2) {
        int n = s1.length();
        string ss1 = s1;
        string ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false;
        if (s1 == s2) return true;
        
        for (int k = 1; k < n; k++) {
            string s1_l1 = s1.substr(0, k);
            string s1_r1 = s1.substr(k);
            string s2_l1 = s2.substr(0, k);
            string s2_r1 = s2.substr(k);
            
            if (Scramble(s1_l1, s2_l1) && Scramble(s1_r1, s2_r1)) return true;
            s1_l1 = s1.substr(0, n - k);
            s1_r1 = s1.substr(n - k);
            if (Scramble(s1_l1, s2_r1) && Scramble(s1_r1, s2_l1)) return true;
        }
        return false;
    }
};

int main(int argc, char **argv) {
	return 0;
}
