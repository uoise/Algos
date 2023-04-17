import java.util.Arrays;

class Solution {
    private void dfs(int cur, boolean[] bv, int[][] vv) {
        for (int i = 0; i < vv[cur].length; i++) {
            if (bv[i] || vv[cur][i] == 0) continue;
            bv[i] = true;
            dfs(i, bv, vv);
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] bv = new boolean[n];
        Arrays.fill(bv, false);
        for (int i = 0; i < n; i++) {
            if (!bv[i]) {
                dfs(i, bv, computers);
                ++answer;
            }
        }
        return answer;
    }
}