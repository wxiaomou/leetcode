//refs to http://www.cnblogs.com/feiling/p/3357067.html "dp + dfs"
public class Solution {
     public ArrayList<String> wordBreak(String s, Set<String> dict) {
        ArrayList<String> ret = new ArrayList();
        int n = s.length();
        if (n == 0) return ret;
        boolean[][] ref = new boolean[n][n + 1];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                if (dict.contains(s.substring(i, i + len))) {
                    ref[i][len] = true;
                    continue;
                }
                
                for (int k = 1; k < len; k++) {
                    if (ref[i][k] && ref[i + k][len - k]) 
                        ref[i][len] = true;
                }
            }
        }
        if (ref[0][n]) dfs(s, dict, 0, 0, ret, new StringBuffer(), ref);
        
        return ret;
    }
    
    private void dfs (String s, Set<String> dict, int start, int depth, ArrayList<String> ret, StringBuffer sb, boolean[][] ref) 
    {
        if (depth == s.length()) {
            String tmp = sb.toString();
            ret.add(tmp.substring(0, tmp.length() - 1));
            return;
        }
        
        for (int i = 1; i <= s.length() - start; i++) {
            if (ref[start][i]) {
                if ( dict.contains(s.substring(start, start + i)) ) {
                    int beforeAddlen = sb.length();
                    sb.append(s.substring(start, start + i) + " ");
                    dfs(s, dict, start + i, start + i, ret, sb, ref);
                    sb.delete(beforeAddlen, sb.length());
                }
            }
        }
    }
    //--------------------------------------------------------------//
    public ArrayList<String> wordBreak(String s, Set<String> dict) {
        ArrayList<String> ret = new ArrayList<String>();
        if (s.length() == 0 ) return ret;
        int length = s.length();
        boolean[][] ref = new boolean[length][length + 1];
        
        for (int len = 1; len <= length; len++) {
            for (int i = 0; i < length - len + 1; i++) {
                if ( dict.contains(s.substring(i, i + len)) ) {
                    ref[i][len] = true;
                    continue;
                }
            
                for (int k = 1; k < len; k++) {
                    if (ref[i][k] && ref[k + i][len - k]) {
                        ref[i][len] = true;
                    }
                }
            }
        }
        if (!ref[0][length]) return ret;
        
        dfs(s, ref, 0, 0, length, new StringBuffer(), ret, dict);
        return ret;
    }
    
    private void dfs(String s, boolean[][] ref, int start, int depth, int length, StringBuffer sb, ArrayList<String> ret, Set<String> dict) {
        if (depth == length) {
            String t = sb.toString();
            ret.add(t.substring(0, t.length() - 1));
            return;
        }
        
        for (int i = 1; i <= length; i++) {
            if (ref[start][i]) {
                if ( dict.contains(s.substring(start, start + i)) ) {
                    int beforeAddLen = sb.length();
                    sb.append(s.substring(start, start + i)).append(" ");
                    dfs(s, ref, start + i, start + i, length, sb, ret, dict);
                    sb.delete(beforeAddLen, sb.length());
                }
            }
        }
        return;
    }
   
    
}