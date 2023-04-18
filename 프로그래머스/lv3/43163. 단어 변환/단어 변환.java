import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public static boolean reachable(String x, String y) {
        int cnt = 0;
        for (int i = 0; i < x.length(); i++) if (x.charAt(i) == y.charAt(i)) ++cnt;
        return cnt == x.length() - 1;
    }

    public int solution(String begin, String target, String[] words) {
        int[] bv = new int[words.length];
        Arrays.fill(bv, 0);
        Queue<Integer> q = new LinkedList<>();
        q.add(-1);
        while (!q.isEmpty()) {
            int idx = q.poll();
            int ord = (idx < 0 ? 1 : bv[idx] + 1);
            String s = idx < 0 ? begin : words[idx];
            for (int i = 0; i < words.length; i++) {
                if (bv[i] == 0 && reachable(s, words[i])) {
                    bv[i] = ord;
                    if (words[i].equals(target)) return bv[i];
                    q.add(i);
                }
            }
        }
        return 0;
    }
}