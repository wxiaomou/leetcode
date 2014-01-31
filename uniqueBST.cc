#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
	int numTrees(int n) {
       if (!n) return 0;
       int ref[n + 1];
       for (int i = 0; i <= n; i++) ref[i] = -1;
       recur(n, ref);
       return ref[n];
    }
    
    int recur(int n, int ref[]) {
        if (n <= 0) return 0;
        if (n == 1) {
            ref[n] = 1;
            return 1;
        }
        if (ref[n] != -1) return ref[n];
        ref[n] = 0;
        for (int i = 1; i <= n; i++) {
            int l = recur(i - 1, ref);
            int r = recur(n - i, ref);
            if (l && r)
                ref[n] += l * r;
            else 
                ref[n] += l ? l : r;
        }
        return ref[n];
    }
    //-----------------------------------------//
	int numTrees(int n) {
		 if (n < 1)
            return 0;
        if (n == 1)
    		return 1;
		int count = 0;
		for (int i = 1; i <= n; i++) {
            int a = numTrees(i - 1);
            int b = numTrees(n - i);
            if (a && b)
			    count += numTrees(i - 1) * numTrees(n - i);
            else 
                count += a + b;
		}
		return count;
	}
};

int main(int argc, char **argv) {
	return 0;
}
