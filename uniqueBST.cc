#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
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
