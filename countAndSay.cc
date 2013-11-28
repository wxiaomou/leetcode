#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    /*string countAndSay(int n) {
			if (n == 0) {
				string ret1 ("");
				return ret1;
			}
   		string ret ("1");
			string res = ret;

			// do it n times
			for (int i = 0; i < n - 1 ; ++i) { 
				int count = 1;
				ret = res;
				res.clear();// don't forget to clear res!!!!!!!!!!!!!!!
				char tmp = ret[0];
				if (i == 0) {
					res = "11";
				} else {
				for (size_t j = 1; j < ret.length(); ++j) {
					if (ret[j] == tmp) {
						count++;
						continue;
					} else {
						tmp = ret[j];
						stringstream begin;
						begin << count;
						res += begin.str() + tmp;
						count = 1;
					}
				}
				// Don't forgot the last one
				stringstream begin;
				begin << count;
				res += begin.str() + tmp;
				cout << "res " << res << endl;
			}
			}

			return res;
		}*/
	// better way
	string countAndSay(int n) {
        if (!n) return "";
        if (n == 1) return "1";
        string ret = "1";
        while (n > 1) {
            n--;
            string res = "";
            for (int i = 0; i < ret.length();) {
                char cur = ret[i];
                int cnt = 0;
                while (ret[i] == cur) {
                    cnt ++;
                    i++;
                }
                stringstream ss, cc;//create a stringstream
                ss << cnt;//add number to the stream
                res += ss.str();
                res += cur;
            }
            ret = res;
        }
        return ret;
    }
};

int main(int argc, char** argv) {
	Solution sol;
	cout << sol.countAndSay(3)	<< endl;
	//string test ("1");
	//cout << test.at(0);
	return 1;
}
