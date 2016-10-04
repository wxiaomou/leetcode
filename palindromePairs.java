public class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        Map<String, Integer> set = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            StringBuffer tmp = new StringBuffer(words[i]).reverse();
            set.put(tmp.toString(), i);
        }
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        for (int i = 0; i < words.length; i++) {
            String str = words[i];
            for (int j = 0; j <= str.length(); j++) {
                String s1 = str.substring(0, j);
                String s2 = str.substring(j);
                if (isPalindrom(s1) && set.containsKey(s2) && i != set.get(s2)) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(set.get(s2));
                    tmp.add(i);
                    ret.add(tmp);
                }
                if (isPalindrom(s2) && set.containsKey(s1) && i != set.get(s1) && j < str.length()) { // Avoid double comput on whole original string.
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(i);
                    tmp.add(set.get(s1));
                    ret.add(tmp);                  
                }
            }
        }
        return ret;
    }
    
    private boolean isPalindrom(String s) {
        char[] c = s.toCharArray();
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (c[i] != c[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
