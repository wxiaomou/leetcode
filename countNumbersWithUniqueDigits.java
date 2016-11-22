public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int ret = 10;
        int cnt = 9;
        for (int i = 2; i <= n; i++) {
            cnt *= (9 - i + 2);
            ret += cnt;
        }
        return ret;
    }
}
