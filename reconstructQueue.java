public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>() {
                                @Override
                                public int compare(int[] o1, int[] o2) {
                                    if (o1[0] > o2[0] || (o1[0] == o2[0] && o1[1] < o2[1])) {
                                        return -1;
                                    }
                                     return 1;
                                }});
                                
        List<Pair> list = new ArrayList<>();
        for (int[] tmp : people) {
            list.add(tmp[1], new Pair(tmp[0], tmp[1]));
        }
        int[][] ret = new int[people.length][2];
        for (int i = 0; i < list.size(); i++) {
            ret[i][0] = list.get(i).first;
            ret[i][1] = list.get(i).second;
        }
        return ret;
    }
    
    private class Pair {
        int first;
        int second;
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
