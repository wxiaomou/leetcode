class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        if (*(p + 1) != '*') {
            if (*s == *p || *p == '.' && *s != 0) //*s != 0 is for special case like s = "", p = '.', which we can refer the commented function.
                return isMatch(s + 1, p + 1);
            else 
                return false;
        } else {
            while (*s == *p || (*p == '.' && *s != 0)) { // s will increase so need to check *s != 0
                if (isMatch(s, p + 2)) return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
    /*bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        if (*s == 0) {
            if (*(p + 1) != '*')
                return false;
            else if (*p == '.')
                    return isMatch(s, p + 2);
        }
        if (*(p + 1) != '*') {
            if (*s == *p || *p == '.')
                return isMatch(s + 1, p + 1);
            else 
                return false;
        } else {
            while (*s == *p || (*p == '.' && *s != 0)) {
                if (isMatch(s, p + 2)) return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }*/
};