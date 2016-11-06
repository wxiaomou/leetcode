public class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        if (len == 0) return true;
        int m = nums[0];
        for (int i = 0; i <= m; i++) {
            if (m >= len -1) return true;
            m = Math.max(m, i + nums[i]);
        }
        return false;
    }
    // Time exceed!
    public boolean canJump(int[] nums) {
        int len = nums.length;
        if (len == 0) return false;
        Queue<Integer> q = new PriorityQueue<>();
        q.add(0);
        int cnt = 1;
        int range = 0;
        while (q.size() > 0) {
            int front = q.poll();
            cnt--;
            range = Math.max(range, nums[front] - cnt);
            if (front + nums[front] >= len - 1) {
                return true;
            }
            if (cnt == 0) {
                for (int i = front + 1; i <= front + range; i++) {
                    // System.out.println(i);
                    q.add(i);
                    cnt++;
                }
                range = 0;
            }
        }
        return false;
    }
}
