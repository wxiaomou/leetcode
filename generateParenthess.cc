#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public: 
	vector<string> generateParenthesis(int n) {
        if (!n) vector<string>();
        return _gen(n, n);
    }
    
    vector<string> _gen(int left, int right) {
        if (!right) return vector<string>(1, "");
        vector<string> ret;
        if (left > 0) {
            vector<string> tmp = _gen(left - 1, right);
            for (int i = 0; i < tmp.size(); ++i) {
                tmp[i] = "(" + tmp[i];
            }
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        
        if (left < right) {
            vector<string> tmp1 = _gen(left, right - 1);
            for (int i = 0; i < tmp1.size(); ++i) {
                tmp1[i] = ")" + tmp1[i];
            }
            ret.insert(ret.end(), tmp1.begin(), tmp1.end());
        }
        return ret;
    }

    /*
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		if (n <= 0)
			return ret;
		return recursion(n, n);
	}	

	vector<string> recursion(int left, int right) {
		//if (left == 0 && right == 0)
			//return ret;
		vector<string> ret;
		if (right == 0 && left ==0) {
			string tmp("");
			ret.push_back(tmp);
			return ret;
		}
		vector<string> tmp;
		if (right > 0) {
			tmp = recursion(left, right - 1);
				for (int i = 0; i < tmp.size(); ++i) {
					string tmp1(")");
					tmp[i] = tmp[i] + tmp1;
					ret.push_back(tmp[i]);
				}
		} 
		if (left > right) {
				tmp = recursion(left - 1, right);
				for (int i = 0; i < tmp.size(); ++i) {
					string tmp1("(");
					tmp[i] = tmp[i] + tmp1;
					ret.push_back(tmp[i]);
				}
		} 
		
		return ret;
		}
	*/
};

int main(int argc, char** argv) {
	Solution sol;
	vector<string> tmp = sol.generateParenthesis(3);

	for (int i = 0; i < tmp.size(); ++i) {
		cout << tmp[i] << endl;
	}
	return 1;
}
