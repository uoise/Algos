class Solution {
    static int[] gv;

    static int fnd(final int x) {
        if (x == gv[x]) return x;
        return gv[x] = fnd(gv[x]);
    }

    static void union(int x, int y) {
        x = fnd(x);
        y = fnd(y);
        if (x == y) return;
        gv[x] = y;

    }

    int sol(final int e, final int[][] wv) {
        for (int i = 1; i < gv.length; i++) gv[i] = i;
        for (int i = 0; i < wv.length; i++) {
            if (i == e) continue;
            union(wv[i][0], wv[i][1]);
        }
        final int tgt = fnd(1);
        int[] ret = {0, 1};
        for (int i = 2; i < gv.length; i++) ++ret[tgt == fnd(i) ? 1 : 0];
        return Math.abs(ret[0] - ret[1]);
    }

    public int solution(int n, int[][] wires) {
        int answer = 101;
        gv = new int[n + 1];
        for (int i = 0; i < wires.length; i++) answer = Math.min(answer, sol(i, wires));
        return answer;
    }
}