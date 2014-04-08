#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
        auto m = a.length();
        auto n = b.length();
        if (!m || !n) return m ? a : b;
        int adv = 0;
        int i = m - 1;
        int j = n - 1;
        string c = ""; 
        int a1 = (a[i] - '0');
        int b1 = (b[j] - '0');
        while (i >= 0 || j >= 0) {
            int tmp = a1 + b1 + adv;
            if (tmp >= 2) {
                tmp %= 2;
                adv = 1;
            } else {
                adv = 0;
            }
            string tmp1 = to_string(tmp);
            c = tmp1 + c;
            i--;
            j--;
            
            if (i >= 0) {
                a1 = a[i] - '0';
            } else {
                a1 = 0;
            }
            
            if (j >= 0) {
                b1 = b[j] - '0';  
            } else {
                b1 = 0;
            }
        }
        
        if (adv) {
            string tmp = "1";
            c = tmp + c;
        }
        return c;
    }
    
    /*string addBinary(string a, string b) {
    	int i = a.length() - 1;
			int j = b.length() - 1;
			int k = i > j ? i : j;
			int carry = 0;
			string ret = "";
			string longer = i > j ? a : b;
			while (k >= 0) {
				if ((i >= 0) && (j >= 0)) {
					if ((a.at(i) - '0') + (b.at(j) - '0') + carry > 1) {
						if ((a.at(i) - '0') + (b.at(j) - '0') + carry == 3) {
							ret = '1' + ret;
						} else {
							ret = '0' + ret;
						}
						carry = 1;
					} else if ((a.at(i) - '0') + (b.at(j) - '0') + carry == 1) {
						carry = 0;
						ret = '1' + ret;
					} else if ((a.at(i) - '0') + (b.at(j) - '0') + carry == 0) {
						carry = 0;
					//	if (k > 1)
							ret = '0' + ret;
					}
				}	
				if ((i < 0) || (j < 0)) {
					if (longer.at(k) - '0' + carry > 1 ) {
						carry = 1;
						ret = '0' + ret;
					} else if (longer.at(k) - '0' + carry == 1) {
						carry = 0;
						ret = '1' + ret;
					} else {
						carry = 0;
						ret = longer.at(k) + ret;
					}
				}
				i--;
				j--;
				k--;
//				cout << ret << endl;
			}
			if (carry)
				ret = '1' + ret;
			return ret;
		}*/
};


int main(int argc, char ** argv) {
	string a = argv[1];// "101101";
	string b = argv[2];//"1011";
	Solution A;
	cout << A.addBinary(a, b) << endl;
}
