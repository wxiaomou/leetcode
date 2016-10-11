public class Solution {
    public int findKthLargest(int[] nums, int k) {
        Comparator<Integer> comparator = new MyComparator();
        PriorityQueue<Integer> queue = 
            new PriorityQueue<Integer>(k, comparator);
        for (int num : nums) {
            if (queue.size() < k) {
                queue.add(num);
                continue;
            }
            if (queue.peek() < num) {
                queue.remove(queue.peek());
                queue.add(num);
            }
        }
        return queue.peek();
    }
    public class MyComparator implements Comparator<Integer>
    {
    @Override
    public int compare(Integer x, Integer y)
    {
        // Assume neither string is null. Real code should
        // probably be more robust
        // You could also just return x.length() - y.length(),
        // which would be more efficient.
        return x - y;
    }
}
}
