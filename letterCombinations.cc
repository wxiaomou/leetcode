#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public: 
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (!digits.length()){
			ret.push_back("");
			return ret;
		}

		vector<string> tmp = letterCombinations(digits.substr(1));

		switch (digits[0] - '0') {
	case 2:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "a";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "b";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "c";
				a += tmp[i];
				ret.push_back(a);
			} 
			break;
	case 3:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "d";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "e";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "f";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
	case 4:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "g";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "h";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "i";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
	case 5:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "j";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "k";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "l";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
	case 6:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "m";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "n";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "o";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
	case 7:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "p";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "q";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "r";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "s";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
	case 8:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "t";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "u";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "v";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
	case 9:
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "w";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "x";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "y";
				a += tmp[i];
				ret.push_back(a);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				string a = "z";
				a += tmp[i];
				ret.push_back(a);
			}
			break;
		default:
			cout << "default" << endl;
			break;
		}

		return ret;
	}
};

int main(int argc, char **argv) {
	Solution sol;
	vector<string> ret = sol.letterCombinations("23");
	for (int i = 0; i < ret.size(); ++i) {
			cout << ret[i] << " ";
	}
	cout << endl;

}
