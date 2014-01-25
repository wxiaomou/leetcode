class Solution {
public:
    //w/o extral space
    bool isPalindrome(string s) {
        int n = s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (!n) return true;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            while(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))&& i < n) i++;
            while(!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))&& j >= 0) j--;
            if (i > j) break;
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    //----------------------------------//
    bool isPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!s.length()) return true;
        vector<char> ref;
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                ref.push_back(s[i]);
            }
        }
        for (int i = 0; i < ref.size() / 2; i++) {
            if (ref[i] != ref[ref.size() - 1 - i]) return false;
        }
        return true;
    }
};