#include <iostream>
#include <stddef.h>
#include <limits.h>
using namespace std;
class Solution {
public:
	/*int atoi(const char *str) {
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
	}*/

	 int atoi(const char *str) {
        if (!(*str)) return 0;
        while (*str == ' ') str++;
        if (!str) return 0;
        bool neg = false;
        if (*str == '+') {
            str ++;
        } else if (*str == '-') {
            neg = true;
            str ++;
        }
        int ret = 0;
        //int pre = 0; !!! cannot use ret < pre to judge if non-neg over flow, because ret overflowed may still larger than pre
        while (str) {
            if (*str >= '0' && *str <= '9') {
                 if (neg) {
                     int tmp = *str - '0';
                     if ( (INT_MIN + tmp) / 10 + ret <= 0 ) { //!!!cannot be (INT_MIN + tmp) + ret * 10 <= 0 because ret * 10 can overflow, 
                     										  //and for neg we need qual here because absolute value INT_MIN is larger that INT_MAX, so we can only use special case to convert the special input which is INT_MIN.
                        ret = ret * 10 + (*str - '0');
                     } else {
                         return INT_MIN;
                     }
                 } else {
                     pre = ret;
                     int tmp = *str - '0';
                     if ((INT_MAX - tmp) / 10 > ret)
                        ret = ret * 10 + (*str - '0');
                     else
                        return INT_MAX;
                 }
            } else {
                break;
            }
            str++;
        }
        
        if (neg) return -ret;
        return ret;
    }

    //-------------------------------------------------------//
    int atoi(const char *str) {
        if (!str) return 0;
        unsigned long ret = 0;
        bool op = false, started = false, neg = false;
        while (*str != '\0') {
            //spaces
            if (*str == ' ' && started) {
                break;
            } else if(*str == ' ') {
                while (*str == ' ') str++;
                continue;
            }
            
            if (*str == '+' || *str == '-') {
                if (op) return false;
                if (*str == '-') neg = true;
                started = true;
                op = true;
            } else if (*str >= '0' && *str <= '9') {
                started = true;
                if ((INT_MAX - (*str - '0')) / 10 < ret) {
                    ret = (unsigned int) INT_MAX + 1;
                    break;
                }
                ret *= 10;
                ret += *str - '0';
            } else {
                break;
            }
            
            str++;
        }
        if (ret > (unsigned long)INT_MAX) {
            if (!neg) return INT_MAX;
            else return INT_MIN;
        }
        if (neg) return -(int)ret;
        return (int)ret;
    }

};
int main() {
	string a("10522545459");
	Solution sol;
	cout << sol.atoi(a.c_str()) << endl;
}
