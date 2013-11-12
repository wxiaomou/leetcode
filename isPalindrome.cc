class Solution {
public:
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