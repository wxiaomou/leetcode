public class Solution {
    public int longestPalindrome(String s) {
        char[] a = s.toCharArray();
        int[] lower = new int[26];
        int[] upper = new int[26];
        for (int cur : a) {
            if (cur >= 'A' && cur <= 'Z') {
                upper[cur - 'A']++;
            } else {
                lower[cur - 'a']++;
            }
        }
        int len = 0;
        int maxOdd = 0;
        for (int i = 0; i < 26; i++) {
            if (upper[i] % 2 == 0) {
                len += upper[i];
            } else {
                len += upper[i] - 1;
                maxOdd = 1;
            }
            if (lower[i] % 2 == 0) {
                len += lower[i];
            } else {
                len += lower[i] - 1;
                maxOdd = 1;
            }
        }
        len += maxOdd;
        return len;
    }
}
