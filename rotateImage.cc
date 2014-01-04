#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i ) {
            vector<int> tmp;
            for (int j = i; j < n - i - 1; ++j) {
                tmp.push_back(matrix[i][j]);
            }
            for (int j = i; j < n - i - 1; ++j) {
                matrix[i][j] = matrix[n - j - 1][i];
            }
            for (int j = i; j < n - i - 1; ++j) {
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j -1];
            }
            
            for (int j = i; j < n - i - 1; ++j) {
               matrix[n - i - 1][n - j -1] = matrix[j][n - i -1];
            }
            for (int j = i; j < n - i - 1; ++j) {
                matrix[j][n - i -1] = tmp[j - i];
            }
        }
    }

	//----------------------------------------------//
	  void rotate(vector<vector<int> > &matrix) {
    	if (matrix.size() == 0)
			return;
		doRotate(matrix, 0);
	}

	void doRotate(vector<vector<int> > &matrix, int n) {
		if (n >= matrix.size() / 2)
			return;

		vector<int> store;
		for (int i = n; i < matrix.size() - n; i++) {
			store.push_back(matrix[i][n]);
			//cout << matrix[i][n] << " ";
		}
		//cout << endl << endl;
		/*for (int i = n; i < matrix.size() - n; i++) {
			matrix[i][n] = matrix[n][i];
		}*/
		for (int i = n; i < matrix.size() - n; i++) {
			matrix[i][n] = matrix[matrix.size() - n - 1][i];
		}
		//print(matrix);
		for (int i = n; i < matrix.size() - n; i++) {
			matrix[matrix.size() - n - 1][i] = matrix[matrix.size() - i - 1][matrix.size() - n - 1];
		}
		//print(matrix);
		for (int i = matrix.size() - n - 1; i >= n; i--) {
		  matrix[i][matrix.size() - n - 1] = matrix[n][i];
		}
		//print(matrix);
		for (int i = n; i < matrix.size() - n; i++) {
			matrix[n][matrix.size() - i - 1] = store[i - n];
		}
		//print(matrix);
		doRotate(matrix, n + 1);
	}

	void print(vector<vector<int> > vec) {
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j <  vec[i].size(); j++) {
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main(int argc, char **argv) {
	vector<vector<int> > vec;
	vector<int> tmp1;
	tmp1.push_back(1);
	tmp1.push_back(2);
	tmp1.push_back(3);
	tmp1.push_back(4);
	vector<int> tmp2;
	tmp2.push_back(5);
	tmp2.push_back(6);
	tmp2.push_back(7);
	tmp2.push_back(8);
	vector<int> tmp3;
	tmp3.push_back(9);
	tmp3.push_back(10);
	tmp3.push_back(11);
	tmp3.push_back(12);
	int a[] = {13, 14, 15, 16};
	vector<int> tmp4(a, a + 4);

	vec.push_back(tmp1);
	vec.push_back(tmp2);
	vec.push_back(tmp3);
	vec.push_back(tmp4);
	Solution sol;
	sol.rotate(vec);
	return 0;
}
