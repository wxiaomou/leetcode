public class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        for (int i = nums.length - 1, s3 = Integer.MIN_VALUE; i >= 0; i--) {
            if (nums[i] < s3) return true;
            while (!stack.empty() && stack.peek() < nums[i]) {
                s3 = Math.max(stack.peek(), s3);
                stack.pop();
            }
            stack.push(nums[i]);
        }
        return false;
    }
}
