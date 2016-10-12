public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Comparator<Node> comparator = new MyComparator();
        PriorityQueue<Node> queue = 
            new PriorityQueue<Node>(k, comparator);
        Map<Integer, Integer> hash = new HashMap<>();
        for (int num : nums) {
            if (hash.containsKey(num)) {
                Integer tmp = hash.get(num);
                hash.remove(num);
                hash.put(num, ++tmp);
            } else {
                hash.put(num, 1);
            }
        }
        for (int num : hash.keySet()) {
            queue.add(new Node(num, hash.get(num)));
        }
        List<Integer> list = new ArrayList<>();
        while (queue.size() > 0 && list.size() < k) {
            list.add(queue.peek().num);
            queue.remove();
        }       
        return list;
    }
    class Node {
        int num;
        int cnt;
        public Node(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }
    public class MyComparator implements Comparator<Node>
    {
    @Override
    public int compare(Node x, Node y)
    {
        // Assume neither string is null. Real code should
        // probably be more robust
        // You could also just return x.length() - y.length(),
        // which would be more efficient.
        return y.cnt - x.cnt;
    }
    }
}
