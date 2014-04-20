#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
 bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l) return false;
        if (!m || !n) return m ? s1 == s3 : s2 == s3;
        vector<int> tmp (n, -1);
        vector<vector<int>> matrix(m, tmp);
        return (dp(0, 0, 0, s1, s2, s3, matrix) == 1);
    }
    
    int dp(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &matrix) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (k == l) return 1;
        if (i == m) {
            if (s2[j] == s3[k])
                return dp(i, j + 1, k + 1, s1, s2, s3, matrix);
            return 0;
        }
        if (j == n) {
            if (s1[i] == s3[k])
                return dp(i + 1, j, k + 1, s1, s2, s3, matrix);
            return 0;
        }
        if (matrix[i][j] != -1) return matrix[i][j];
        if (s1[i] == s3[k]) {
            matrix[i][j] = dp(i + 1, j, k + 1, s1, s2, s3, matrix);
            if (matrix[i][j] == 1) return 1;
        }
        
        if (s2[j] == s3[k]) {
            matrix[i][j] = dp(i, j + 1, k + 1, s1, s2, s3, matrix);
            if (matrix[i][j] == 1) return 1;
        }
        return 0;
    }

	//---------------------------------------------------//
	int ** _m;
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int k = s3.length();
        if (!k) return true;
        if (m + n != k) return false;
        _m = new int*[m];
        if (!m) return s2 == s3;
        if (!n) return s1 == s3;
        for (int i = 0; i < m; i++) _m[i] = new int [n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                _m[i][j] = -1;
        // _m[m - 1][n - 1] = 1;
        if (dp(s1, s2, s3, 0, 0) > 0)
            return true;
        else 
            return false;
    }
    
    int dp(string &s1, string &s2, string &s3, int i, int j) {
        int m = s1.size(), n = s2.size();
        if (i == m && j == n) return 1;
        int ret1 = 0, ret2 = 0;
        if (i == m) {
            if (s2[j] == s3[i + j])
                return dp(s1, s2, s3, i, j + 1);
            else 
                return 0;
        }
        if (j == n) {
            if (s1[i] == s3[i + j])
                return dp(s1, s2, s3, i + 1, j);
            else 
                return 0;
        }
        //operations associated w/ _m should happend here, because above may exceed the matrix's range
        if (_m[i][j] != -1) return _m[i][j];
        if (i < m && s1[i] == s3[i + j]) ret1 = dp(s1, s2, s3, i + 1, j);
        if (j < n && s2[j] == s3[i + j]) ret2 = dp(s1, s2, s3, i, j + 1);
        _m[i][j] = ret1 | ret2;
        return _m[i][j];
    } 
    
	//----------------------------------------------------------//
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

};g


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
