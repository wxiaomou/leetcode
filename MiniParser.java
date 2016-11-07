/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {
    public NestedInteger deserialize(String s) {
        int len = s.length();
        NestedInteger ret = new NestedInteger();
        if (len == 0 || s.equals("[]")) {
            return ret;
        }
        int neg = 1;
        int i = 0;
        if (s.charAt(0) != '[') {
            ret.setInteger(strToInt(s));
            return ret;
        }
        while (i < len) {
            System.out.println(i);
            if (s.charAt(i) == '[' && i > 0) {
                int leftCnt = 1;
                int start = i;
                i++;
                while (leftCnt > 0) {
                    if (s.charAt(i) == '[') {
                        leftCnt++;
                    } 
                    if (s.charAt(i) == ']') {
                        leftCnt--;
                    }
                    i++;
                }
                ret.add(deserialize(s.substring(start, i - 1)));
            } else if (s.charAt(i) != '[') {
                int start = i;
                while (i < len && s.charAt(i) != ',' && s.charAt(i) != ']') {
                    i++;
                }
                if (i > start) {
                    ret.add(new NestedInteger(strToInt(s.substring(start, i))));
                }
                i++;
            } else {
                i++;
            }
        }
        return ret;
    }
    
    int strToInt(String tmp) {;
        int neg = 1;
        if (tmp.charAt(0) == '-') {
            neg = -1;
            tmp = tmp.substring(1);
        }
        int cur = Integer.parseInt(tmp);
        return cur * neg;
    }
}
