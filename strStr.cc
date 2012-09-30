#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class Solution {
public:
	class Solution {
public:
char *strStr(char *haysstack, char *needle) {
        int m = strlen(haysstack);
		int n = strlen(needle);

    	if (!m || !n) {
            if (strlen(haysstack) < strlen(needle))
			    return NULL;
        	return m > n ? haysstack: haysstack + 1;
    	}
	
		char *head = haysstack;
		int i = 0;
			while(i != m) {
				if (head[i] == *needle) {
					if(ifSame(&head[i], needle))
						return &head[i];
				}
				i++;
			}
			return NULL;
	}

	bool ifSame(char *str1, char *str2) {
		if(strlen(str1) < strlen(str2))
			return false;
		int i = 0;
		while (str2[i] != '\0') {
			if (*str1 == str2[i]) {
					str1++;
					i++;
			} else {
				return false;
			}
		}
		return true;
	}

};
};

int main(int argc, char **argv) {
Solution sol;
char a[] = {"mississppi"};
char b[] = {"a"};
cout << sol.strStr(a, b) << endl;
}

