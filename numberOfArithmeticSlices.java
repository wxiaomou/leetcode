public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int len = A.length;
        if (len < 3) return 0;
        int ret = 0;
        for (int i = 1; i < len;) {
            int diff = A[i] - A[i - 1];
            int j = i + 1;
            while (j < len && A[j] - A[j - 1] == diff) {
                j++;
                if (j - i >= 2) {
                    ret++;
                    ret += j - (i - 1) - 3;
                }
            }
            i = j;
        }
        return ret;
    }
}
