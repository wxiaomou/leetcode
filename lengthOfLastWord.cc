#include <iostream>

using namespace std;

class Solution {
public:
	 int lengthOfLastWord(const char *s) {
        if (*s == '\0') return 0;
        const char *str = s;
        int len = 0;
        bool space = false;
        while (*str != '\0') {
            if (space) {
                len = 0; 
                space = false;
            }
            while (*str != '\0' && *str != ' ') {
                len++;
                str++;
            }
            if (*str == '\0') break;
            while (*str == ' ') {
                space = true;
                str++;
            }
        }
        return len;
    }
	//-------------------------------------//
	int lengthOfLastWord(const char *s) {
        int len = 0;
		if (!s)
			return len;
		int i = 0;
		while (s[i] == ' ') i++;
		while (s[i] != ' ' && s[i] != '\0') {
			len++;
			i++;
		}

		if (s[i] == '\0')
			return len;
		else {
			int tmp = lengthOfLastWord(s + i + 1);
            if (tmp == 0)
                return len;
            else 
                return tmp;
		}
	}
};

int main(int argc, char **argv) {
	Solution sol;
	cout << sol.lengthOfLastWord("Hello World  ") << endl;
}
