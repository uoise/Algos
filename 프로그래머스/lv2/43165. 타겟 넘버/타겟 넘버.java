import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    class Iv {
        int idx;
        int val;

        public Iv(int idx, int val) {
            this.idx = idx;
            this.val = val;
        }
    }

    private static final Queue<Iv> q = new ArrayDeque<>();

    public int solution(int[] numbers, int target) {
        int answer = 0, siz = numbers.length - 1;
        q.add(new Iv(-1, 0));
        while (!q.isEmpty()) {
            Iv cur = q.poll();
            if (cur.idx++ == siz) {
                if (cur.val == target) ++answer;
                continue;
            }
            q.add(new Iv(cur.idx, cur.val + numbers[cur.idx]));
            q.add(new Iv(cur.idx, cur.val - numbers[cur.idx]));
        }
        return answer;
    }
}