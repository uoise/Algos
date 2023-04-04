import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    private static boolean[] bv;

    public int sol(int k, int[][] dv) {
        int ret = 0;
        for (int i = 0; i < dv.length; i++) {
            if (bv[i] || k < dv[i][0]) continue;
            bv[i] = true;
            ret = Math.max(ret, sol(k - dv[i][1], dv));
            bv[i] = false;
        }
        return Math.max(ret, IntStream.range(0, dv.length).map(i -> bv[i] ? 1 : 0).sum());
    }

    public int solution(int k, int[][] dungeons) {
        bv = new boolean[dungeons.length];
        Arrays.fill(bv, false);
        return sol(k, dungeons);
    }
}