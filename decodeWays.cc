#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	int count;
	int numDecoding(string s) {
		if (s.length() == 0)
			return 0;
		count = 0;
		recursion(s);
		return count;
	}
	
	void recursion(string s) {
		if (s.length() == 0) {
			count++;
		} else {
			int tmp = s[0] - '0';
			if (tmp > 0 && tmp <= 9) {
				recursion(s.substr(1));	
				
				if (s.length() >= 2) {
					tmp = (s[0] - '0') * 10 + (s[1] - '0');
					
					if (tmp > 0 && tmp <= 26) {
						recursion(s.substr(2));
				}
			}
		}

		}

	}

};

int main(int argc, char **argv) {
	return 1;
}
