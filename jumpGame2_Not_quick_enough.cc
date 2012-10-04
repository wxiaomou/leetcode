#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
            int m[n];
            if (n < 2)
                return 0;
            m[n - 1] = 0;
		for (int i = n - 2; i >= 0; --i) {
			if (A[i] >= n - i - 1) {
				m[i] = 1;
        continue;
			}

			if (A[i] == 0) {
				m[i] = 10000;
			} else {
				int tmp = m[i + 1];
				for (int j = 2; j <= A[i]; j++) {
					 tmp = min(tmp, m[i + j]);
				}
				m[i] = 1 + tmp;
			}
			//cout << m[i] << " ";
		}
		for (int i = 0; i < n; ++i)
			cout << m[i] << " ";
		return m[0];
    }
};

int main(int argc, char **argv) {
Solution sol;

int A[] = {2, 0, 2, 0, 1};
cout << sol.jump(A, 5) << endl;


}
