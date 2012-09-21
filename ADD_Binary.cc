#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
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
		}
};


int main(int argc, char ** argv) {
	string a = argv[1];// "101101";
	string b = argv[2];//"1011";
	Solution A;
	cout << A.addBinary(a, b) << endl;
}
