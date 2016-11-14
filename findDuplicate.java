public class Solution {
    public int findDuplicate(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        int min = 1;
        int max = len - 1;
        while (min < max) {
            int mid = (min + max) / 2;
            int cnt = 0;
            for (int tmp : nums) {
                if (tmp <= mid) {
                    cnt++;
                } 
            }
            if (cnt > mid) {
                // (min + max) / 2 will lose one, eg (1 + 4) / 2  = 2, so we can give mid to max rather than mid - 1.
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }
}
