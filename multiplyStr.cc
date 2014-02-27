#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
    		return "0";
		
		vector<int> res(num1.size() + num2.size(), 0);

		
		for (int i = 0; i < num1.size(); ++i) {
            int carry = 0;
			for (int j = 0; j < num2.size(); ++j) {
				int d1 = num1[num1.size() - i - 1] - '0';
				int d2 = num2[num2.size() - j - 1] - '0';

				carry = carry + res[i + j] + d1 * d2;
				res[i + j] = carry % 10;
				carry /= 10;
			}
			res[i + num2.size()] = carry;
		}

		int p = res.size() - 1;
		string ret;
		while (res[p] == 0 && p > 0) p--;
    	while (p >= 0) ret += char (res[p--] + '0'); 
		
		return ret;
	}
};

//-------------------------------------------//
 string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num2.length();
        if (!n) return num1;
        string ret = "0";
        int adv = 0;
        for ( auto i = n - 1; i >= 0; --i ) {
            int b = num2[i] - '0';
            adv = 0;
            if (i < n - 1)
                num1 += '0';
            int m = num1.size();
            string cur = num1;
            for ( auto j = m - 1; j >= 0; --j ) {
                int tmp = cur[j] - '0';
                tmp = tmp * b + adv;
                adv = tmp / 10;
                tmp = tmp % 10;
                cur[j] = tmp + '0';
            }
            if (adv > 0) {
                char tmp = '0' + adv;
                cur = tmp + cur;
            }
            ret = plus(ret, cur);
        }
        return ret;
    }
    
    string plus(string a, string b) {
        int m = a.length();
        int n = b.length();
        if (a == "0") return b;
        if (b == "0") return a;
        int adv = 0;
        int i = m - 1;
        int j = n - 1;
        string ret = "";
        while (i >= 0 && j >= 0) {
            int tmp = a[i] - '0' + b[j] - '0' + adv;
            adv = tmp / 10;
            tmp %= 10;
            char tmp1 = '0' + tmp;
            ret = tmp1 + ret;
            i--;
            j--;
        }
        string c = i >= 0 ? a : b;
        int k  = i >= 0 ? i : j;
        while (k >= 0 || adv) {
            int tmp = 0;
            if (k >= 0 )
                tmp = c[k] - '0';
            tmp += adv;
            adv = tmp / 10;
            tmp %= 10;
            char tmp1 = '0' + tmp;
            ret = tmp1 + ret;
            k--;
        }
        return ret;
    }

int main (int argc, char **argv) {
	return 0;
}
