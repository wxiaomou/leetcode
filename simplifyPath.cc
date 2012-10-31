#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
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
				while (path[j + 1] != '/'&& j < path.length() ) j++;
				string com = path.substr(i, j - i + 1);
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
