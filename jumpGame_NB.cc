#include<iostream>

using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (!n)
			return true;

		int m = 0;

		for (int i = 0; i <= m; ++i) {
			if (m >= n - 1)
				break;
			m = m > (i + A[i]) ? m : (i + A[i]);
		}

		return m >=i n - 1;

		//--------------------------//
		bool canJump(int A[], int n) {
        if(!n) return true;
        int i = 0;
        int dist = i + A[i];
        while (i < n) {
            int ref = i;
            int j;
            for (j = i; j < n && j <= dist; j++) {
                if (ref + A[ref] <= j + A[j]) {
                    ref = j;
                }
            }
            if (j >= n) return true;
            i = ref;
            dist = i + A[i];
            if (dist >= n - 1) return true;
            if (dist == i) return false;
        }
    }
	}


};
