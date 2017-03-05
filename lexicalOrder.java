public class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ret = new ArrayList<>();
        int i = 1;
        while (i <= n) {
            ret.add(i++);
        }
        Collections.sort(ret, new CustomComparator(n));
        return ret;
    }
    
    public class CustomComparator implements Comparator<Integer> {
        int top;
        CustomComparator(int n) {
            top = n;
        }
    @Override
    public int compare(Integer o1, Integer o2) {
        int top1 = 1;
        while (top1 < top) {
            top1 *= 10;
        }
        while (o1 < top1) o1 *= 10;
        while (o2 < top1) o2 *= 10;
        return o1 - o2;
    }
}
}


public class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ret = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            if (i <= n) {
                recur(i, n, ret);
            }
        }
       return ret;
    }
    
    void recur(int cur, int n, List<Integer> ret) {
        ret.add(cur);
        for (int i = 0; i < 10; i++) {
            if (cur * 10 + i <= n) {
                recur(cur * 10 + i, n, ret);
            }
        }
    }
}
