import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    class Vyx implements Comparable<Vyx> {
        int v;
        int y;
        int x;
        int c;

        public Vyx(int v, int y, int x, int c) {
            this.v = v;
            this.y = y;
            this.x = x;
            this.c = c;
        }

        @Override
        public int compareTo(Vyx o) {
            return v - o.x;
        }
    }

    private static final PriorityQueue<Vyx> pq = new PriorityQueue<>();
    private static final int[] xx = {1, 0, -1, 0};
    private static final int[] yy = {0, 1, 0, -1};
    private static int ys, xs, k;

    public int djs(int y, int x, int[][] vv) {
        int[][] cv = new int[ys][xs];
        for (int i = 0; i < ys; i++) Arrays.fill(cv[i], 0x3f3f3f3f);
        pq.add(new Vyx(vv[y][x], y, x, 0));
        Vyx cur;
        int cnt = 0;
        while (!pq.isEmpty()) {
            cur = pq.poll();
            cnt = Math.max(cnt, cur.c);
            for (int d = 0; d < 4; d++) {
                y = cur.y + yy[d];
                x = cur.x + xx[d];
                if (y < 0 || y >= ys || x < 0 || x >= xs) continue;
                if (vv[y][x] + cur.v > cv[y][x] && vv[y][x] + cur.v > k) continue;
                cv[y][x] = vv[y][x] + cur.v;
                pq.add(new Vyx(vv[y][x] + cur.v, y, x, cur.c + 1));
            }
        }
        return cnt;
    }

    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        Solution.k = k;
        ys = dungeons.length;
        xs = dungeons[0].length;
        for (int y = 0; y < ys; y++)
            for (int x = 0; x < xs; x++)
                answer = Math.max(answer, djs(y, x, dungeons));
        return answer;
    }
}