import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class Solution {
    class Pi {
        int val;
        boolean tgt;

        public Pi(int val, boolean tgt) {
            this.val = val;
            this.tgt = tgt;
        }
    }

    public int solution(int[] priorities, int location) {
        int answer = 0;
        int[] mp = new int[10];
        Arrays.fill(mp, 0);
        Queue<Pi> q = new ArrayDeque<>();
        for (int i = 0; i < priorities.length; i++) {
            ++mp[priorities[i]];
            q.add(new Pi(priorities[i], i == location));
        }

        while (!q.isEmpty()) {
            Pi cur = q.poll();
            boolean chk = false;
            for (int i = cur.val + 1; !chk && i < 10; i++) {
                if (mp[i] > 0) {
                    chk = true;
                    q.add(cur);
                }
            }
            if (chk) continue;
            ++answer;
            --mp[cur.val];
            if (cur.tgt) return answer;
        }
        return answer;
    }
}