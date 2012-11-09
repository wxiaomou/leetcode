#include <iostream>
#include <stddef.h>
#include <limits.h>
using namespace std;
class Solution {
public:
	int atoi(const char *str) {
		if (!*str)
			return 0;
		int res = 0;
		while (*str == ' ') str++;
		if (!*str)
			return 0;
		bool isMinus = false;
		if (*str == '-') {
			isMinus = true;
			str++;
		} else if (*str == '+')
			str++;

		if (*str == '+' || *str == '-') // !!!*str == "";
			return 0;
		//while (*str == '+' || *str == '-') {
			//if (*str == '-')
			//	isMinus = !isMinus;
			//str++;
		//}
		while(*str) {
	//		cout << res << endl;
			int pre = res;
				if (*str <= '9' && *str >= '0') {
					if (!isMinus) {
						if ((INT_MAX - (*str - '0')) / 10 >= res) {
							res = res * 10 + (*str - '0');
						} else {
							return INT_MAX;
						}
				 } else if ((INT_MIN + (*str - '0')) / 10 <= -res) {
							res = res * 10 + (*str - '0');
						} else {
							return INT_MIN;
						}
					
					} else 
							break;
			str++;
		}	
		if (isMinus)
			res = -res;
	return res;
	}
};
int main() {
	string a("10522545459");
	Solution sol;
	cout << sol.atoi(a.c_str()) << endl;
}
