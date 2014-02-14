#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
        if (!n || n == 1) return 0;
        int ret = 0;
        int i = 0;
        int dist = 0;
        while (i < n) {
            dist = A[i] + i;
            if (dist >= n - 1) return ret + 1;
            int ref = 0;
            for (int j = i + 1; j <= i + A[i]; ++j) {
                if (A[j] + j > dist) {
                    dist = A[j] + j;
                    ref = j;
                }
            }
            i = ref;
            ret++;
        }
    }
    
    /*int jump(int A[], int n) {
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
    }*/
};

int main(int argc, char **argv) {
Solution sol;

int A[] = {2, 0, 2, 0, 1};
cout << sol.jump(A, 5) << endl;


}
