public class Solution {
    public int nthUglyNumber(int n) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (list.size() < n) {
            int tmp2 = list.get(i2) * 2;
            int tmp3 = list.get(i3) * 3;
            int tmp5 = list.get(i5) * 5;
            int tmp = Math.min(tmp2, Math.min(tmp3, tmp5));
            if (tmp == tmp2) {
                i2++;
            }
            if (tmp == tmp3) {
                i3++;
            }
            if (tmp == tmp5) {
                i5++;
            }
            list.add(tmp);
        }
        return list.get(list.size() - 1);
    }
}
