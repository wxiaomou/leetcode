#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
	int **m;
    bool isInterleave(string s1, string s2, string s3) {
	 if (s3.length() != (s1.length() + s2.length())) {
		 return false;
	 }    
   		if (s1.length() == 0) {
  		return s2.compare(s3) == 0 ? true : false;	
		}
		if (s2.length() == 0) {
			return s1.compare(s3) == 0 ? true : false;
		}

		int l1 = s1.length();
		int l2 = s2.length();
		m = new int*[l1];

		for(int i = 0; i < l1; ++i) m[i] = new int[l2];


		for (int i = 0; i < l1; ++i) {
			for (int j = 0; j < l2; ++j) m[i][j] = -1;
		}
		
		dp(s1, s2, s3, 0, 0);
/*
		for (int i = 0; i < l1; ++i) {
			for (int j = 0; j < l2; ++j)
				cout << m[i][j] << " ";
			cout << endl;
		}
*/
		if (m[0][0] == 1)
			return true;
		else 
			return false;
	}

	int dp(string s1, string s2, string s3, int i, int j) {
	// base situation
	//	cout << "i:" << i << " j:" << j << endl;
	//	if (m[i][j] != -1)
	//		return m[i][j];
		if (i == s1.length()) {
		//	m[i][j] = compare(s2.substr(j), s3.substr(i + j));
		//	return m[i][j];
				return compare(s2.substr(j), s3.substr(i + j));
		}

		if (j == s2.length()) {
		//	m[i][j] = compare(s1.substr(i), s3.substr(i + j));
		//	return m[i][j];
				return compare(s1.substr(i), s3.substr(i + j));
		}
		if (m[i][j] != -1)
			return m[i][j];
	
		int ret = 0;
		int ret1 = 0;
		if (s1[i] == s3[i + j]) {
			ret = dp(s1, s2, s3, i + 1, j);
			//m[i][j] = ret;
		} 
		if (s2[j] == s3[i + j]) {
			ret1 = dp(s1, s2, s3, i, j + 1);
			//m[i][j] = ret;
		} //else 
		//	m[i][j] = 0;
		if ((ret == 0) && ret1 == 0)
			m[i][j] = 0;
		else 
			m[i][j] = 1;

		return m[i][j];

	}

	int compare(string s1, string s2) {
		//cout << "s1:" << s1 << endl;
		//cout << "s2:" << s2 << endl;
		if ((s1.length() == s2.length()) && s1.length() == 0)
			return 1;
		if (strcmp(s1.c_str(), s2.c_str()) == 0)
			return 1;
		else 
			return 0;
	}

};

int main(int argc, char **argv) {
	Solution sol;
	string s1("aabaac");
	string s2("aadaaeaaf");
	string s3("aadaaeaabaafaac");
	string s4("aadbbbaccc");

	 if (sol.isInterleave(s1, s2, s3)) {
			cout << "s3 is true" << endl;
	 } else {
			cout << "s3 is false" << endl;
	 }
	/* 
	 if (!sol.isInterleave(s1, s2, s4)) {
			cout << "s4 is false" << endl;
	 }*/

}
