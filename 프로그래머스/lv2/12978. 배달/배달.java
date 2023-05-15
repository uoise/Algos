import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.stream.IntStream;

class Solution {
    public int solution(int N, int[][] road, int K) {
        int[][] vv = new int[N + 1][N + 1];
        int[] dv = new int[N + 1];
        for (int[] v : vv) Arrays.fill(v, 0x3f3f3f3f);
        Arrays.fill(dv, 0x3f3f3f3f);
        for (int[] r : road) {
            vv[r[0]][r[1]] = Math.min(vv[r[0]][r[1]], r[2]);
            vv[r[1]][r[0]] = Math.min(vv[r[1]][r[0]], r[2]);
        }
        final PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> -o[0]));
        dv[1] = 0;
        pq.add(new int[]{dv[1], 1});
        while (!pq.isEmpty()) {
            int cst = pq.peek()[0];
            int cur = pq.peek()[1];
            pq.poll();
            for (int i = 1; i <= N; i++) {
                if (dv[i] <= vv[cur][i] + cst) continue;
                dv[i] = vv[cur][i] + cst;
                pq.add(new int[]{dv[i], i});
            }
        }
        return (int) IntStream.rangeClosed(1, N).filter(i -> dv[i] <= K).count();
    }
}