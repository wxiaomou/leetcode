#include <iostream>
#include <vector>

using namespace std;
class Solition {
public:
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
