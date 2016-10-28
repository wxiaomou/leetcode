public class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int prepre = nums[0];
        if (len < 2) {
            return prepre;
        }
        int pre = Math.max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            int tmp = prepre + nums[i];
            prepre = pre;
            pre = Math.max(pre, tmp);
        }
        return pre;
    }
}
