#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	 string simplifyPath(string path) {
        string ret = "";
        if (path[path.length() - 1] == '/') path = path.substr(0, path.length() - 1);
        if (path[0] == '/') path = path.substr(1);
        stack<string> s;
        int n = path.length();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && path[j] != '/') j++;
            if (i == j) continue;
            string tmp = path.substr(i, j - i);
            if (tmp == "..") {
                if (!s.empty()) s.pop();
            } else if (tmp != ".") {
                s.push(tmp);
            }
            i = j;
        }
        while (!s.empty()) {
            string tmp = s.top();
            ret = tmp + ret;
            s.pop();
            ret = "/" + ret;
        }
        if (ret.size() == 0) ret = "/";
        return ret;
    }
	//--------------------------------------//
	string simplifyPath(string path) {
		  if (path.length() == 1)
    		return "/";
        if (path[path.length() - 1] == '/')
            path = path.substr(0, path.length() - 1);
 
		stack<string> stac;
		for (int i = 0; i < path.length() - 1; i++) {
				int j = i;
			if (path[i] == '/' && path[i + 1] == '/')
				continue;
			else {
				while (path[j + 1] != '/'&& j < path.length() - 1 ) j++;
				string com;
				if (j == path.length() - 1) 
					com = path.substr(i);
				else
					com = path.substr(i, j - i + 1);
				//cout << "!!" << path.substr(i, j - i + 1) << endl; 
					if (com == "/..")
						if (!stac.empty()) {
							stac.pop();
							i = j;
							continue;
						} else {
    					 i = j;
                         continue;
						} else if (com == "/.") {
        		    i = j;
                    continue;
    			 }
                    
				}
				stac.push(path.substr(i, j - i + 1));
				i = j;
				}
			
        if (stac.empty())
            return "/";
		string res = "";
		while(!stac.empty()) {
			string tmp = stac.top();
			stac.pop();
			res = tmp + res;
		}
	return res;
	}
};

int main(int argc, char **argv) {
	string a = "/a/./b/../../c/";
	Solution sol;
	cout << sol.simplifyPath(a) << endl;
	return 0;
}
