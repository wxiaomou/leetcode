j
class Solution {
	public:
    bool isMatch(const char *s, const char *p) {
        bool isStar = false;
        const char *ptr = p, *str = s;
        while(*str != '\0') {
            switch (*ptr) {
                case '?':
                    str++;
                    ptr++;
                    break;
                case '*':
                    isStar = true;
                    while(*ptr == '*') ptr++;
                    if (*ptr == '\0') return true;
                    p = ptr;
                    s = str; //remember the position of str when ptr met "*". if met mismatch afterwards will backtrace here.
                    break;
                default:
                    if (*str != *ptr) {
                        if (!isStar) return false;
                        ptr = p;
                        s++; //s initial is the element in s when ptr met '*', here we met a not match, so we let s increase one which will fit in '*', 
                             //and recover str and ptr to the position where just after '*' happened.
                        str = s;
                    } else {
                        ptr++;
                        str++;
                    }
            } 
        }
        while (*ptr == '*') ptr++;
        return *ptr == '\0';
    }

        //----------------------------------------------//
		    bool isMatch(const char *s, const char *p) {
                const char * str = s;
                const char * ptr = p;
                bool star = false;
                
                for (; *str != '\0'; str++, ptr++) {
                    switch(*ptr) {
                        case '?':
                            break;
                        case '*':
                            s = str;
                            p = ptr;
                            star = true;
                            while(*p == '*')
                                p++;
                            if (*p == '\0')
                                return true;
                            str = s - 1;
                            ptr = p - 1;
                            break;
                        default:
                        {
                            if (*str != *ptr) {
                                if (!star)
                                    return false;
                                s++;
                                str = s - 1;
                                ptr = p - 1; // p always be the one after '*' or start; so one met mismatch, ptr will go back the one after '*', 
											// s will go back and increase one which match '*'. e.g. s = 'aacbc' p = 'a*c', when str point to b and ptr is '\0'
											//	mismatch, ptr go back to p which is 'c' str go back 'b' which increaed by one to jump the mismatched 'c'
                            }
                        }   
                    }   
                }   
                while (*ptr == '*')
                    ptr++;
                return (*ptr == '\0');
                
            }        
};

int main() {
	Solution sol;
	if (sol.isMatch("aabc", "a*b")) cout << "True" << endl;
	else cout << "False" << endl;
	return 0;
}
