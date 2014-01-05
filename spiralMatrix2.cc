#include <iostream>
#include <vector>

using namespace std;
class Solition {
public:
	vector<vector<int> > generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> ret(n, tmp);
        int num = 1;
        int row_s = 0, row_e = n - 1, col_s = 0, col_e = n - 1;
        while (row_s <= row_e) {
            if (row_s == row_e) {
                ret[row_s][col_s] = num;
            } else {
                for (int j = col_s; j <= col_e; j++) ret[row_s][j] = num++;
                for (int i = row_s + 1; i <= row_e; i++) ret[i][col_e] = num++;
                for (int j = col_e - 1; j >= col_s; j--) ret[row_e][j] = num++;
                for (int i = row_e - 1; i > row_s; i--) ret[i][col_s] = num++;
            }
            row_s++;
            row_e--;
            col_s++;
            col_e--;
        }
        return ret;
    }
	//---------------------recursion-----------------//
	vector<vector<int> > generateMatrix(int n) {
		vector<int> tmp(n, 0);
		vector<vector<int> > res(n, tmp);
		fill(res, n, 0, 1);
		return res;
	}
	void fill(vector<vector<int> > &res, int n, int k, int begin) {
		if (n <= 0)
			return;
		if (n == 1) {
			res[k][k] = begin;
			return;
		}
		
		for (int i = 0; i < n - 1; i++) res[k][k + i] = begin++;
		for (int j = 0; j < n - 1; j++) res[k + j][k + n - 1] = begin++;
		for (int i = 0; i < n - 1; i++) res[k + n - 1][k + n - 1- i] = begin++;
		for (int j = 0; j < n - 1; j++) res[k + n - 1 - j][k] = begin++;
		fill(res, n - 2, k + 1, begin);
		return;
	}
};

int main(int argc, char **argv) {
	return 0;
}
