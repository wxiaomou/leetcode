public class Solution {
    public int minMoves(int[] nums) {
        int sum = IntStream.of(nums).sum();
        int min = nums[0];
        for (int m : nums) {
            min = Math.min(min, m);
        }
        return sum - min * nums.length;
    }
}
