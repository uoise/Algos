import java.util.PriorityQueue;

class Solution {
    public int solution(int[] cards) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        q.add(0);
        q.add(0);
        boolean[] bv = new boolean[cards.length];
        for (int i = 0; i < cards.length; i++) {
            if (bv[i]) continue;
            int cur = i, cnt = 0;
            while (!bv[cur]) {
                bv[cur] = true;
                ++cnt;
                cur = cards[cur] - 1;
            }
            q.add(cnt);
            if (q.size() > 2) q.poll();
        }

        return q.poll() * q.poll();
    }
}