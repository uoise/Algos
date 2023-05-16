class Solution {
    boolean[][] vv;
    int siz, answer = 0;

    void dfs(final int cur, final int shp, final int wlf, final boolean[] bv) {
        if (shp <= wlf) return;
        boolean[] nv = bv.clone();
        nv[cur] = false;
        answer = Math.max(answer, shp);
        for (int i = 0; i < vv.length; i++) {
            if (cur == i || !vv[cur][i]) continue;
            nv[i] = true;
        }

        for (int i = 0; i < bv.length; i++) {
            if (!nv[i]) continue;
            nv[i] = false;
            dfs(i, shp + (vv[i][i] ? 1 : 0), wlf + (vv[i][i] ? 0 : 1), nv);
            nv[i] = true;
        }
    }

    public int solution(int[] info, int[][] edges) {
        siz = info.length;
        vv = new boolean[siz][siz];
        for (int i = 0; i < info.length; i++) vv[i][i] = info[i] == 0;
        for (int[] e : edges) vv[e[0]][e[1]] = true;
        dfs(0, (vv[0][0] ? 1 : 0), (vv[0][0] ? 0 : 1), vv[0]);
        return answer;
    }
}