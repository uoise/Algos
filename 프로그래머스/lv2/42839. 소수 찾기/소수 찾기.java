import java.util.HashSet;
import java.util.Set;

class Solution {
    static Set<Integer> set;
    static boolean[] bv, pr;

    static void dfs(int len, StringBuilder q, final String s) {
        if (len == bv.length) {
            if (q.length() == 0) return;
            int tgt = Integer.parseInt(q.toString());
            if (!pr[tgt]) set.add(tgt);
            return;
        }

        for (int i = 0; i < bv.length; i++) {
            if (bv[i]) continue;
            q.append(s.charAt(i));
            bv[i] = true;
            dfs(len + 1, q, s);
            q.deleteCharAt(q.length() - 1);
            bv[i] = false;
            dfs(len + 1, q, s);
        }
    }

    public int solution(String numbers) {
        pr = new boolean[(int) (Math.pow(10, numbers.length()) + 1)];
        bv = new boolean[numbers.length()];
        set = new HashSet<>();
        pr[0] = pr[1] = true;
        for (int i = 2; i < pr.length; i++)
            if (!pr[i])
                for (int j = 2; i * j < pr.length; j++) pr[i * j] = true;
        dfs(0, new StringBuilder(), numbers);
        return set.size();
    }
}