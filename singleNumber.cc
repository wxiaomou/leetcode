class Solution {
public:
	
    int singleNumber(int A[], int n) {
        if (!n) return 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret ^= A[i];
        }
        return ret;
    }
};