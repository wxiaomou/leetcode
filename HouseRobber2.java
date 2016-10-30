public class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return Math.max(nums[0], nums[1]);
        }
        if (len == 3) {
            return Math.max(Math.max(nums[0], nums[1]), nums[2]);
        }
        int ret = 0;
        int prepre = nums[1];
        int pre = Math.max(nums[1], nums[2]);
        for (int i = 3; i < len; i++) {
            int tmp = pre;
            pre = Math.max(pre, prepre + nums[i]);
            prepre = tmp;
        }
        if (len == 4) {
            return Math.max(nums[0] + nums[2], nums[1] + nums[3]);
        }
        ret = pre;
        prepre = nums[2];
        pre = Math.max(nums[2], nums[3]);
        for (int i = 4; i < len - 1; i++) {
            int tmp = pre;
            pre = Math.max(pre, prepre + nums[i]);
            prepre = tmp;
        }
        return Math.max(ret, pre + nums[0]);
    }
}
