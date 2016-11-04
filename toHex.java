public class Solution {
    public String toHex(int num) {
        if (num == 0) return "0";
        char[] map = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        StringBuffer ret = new StringBuffer();
        while (num != 0) {
            ret.insert(0, map[num & 15]);
            num >>>= 4;
        }
        return ret.toString();
    }
}
