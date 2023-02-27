class Solution {
    public int[][] solution(int[] v, int n) {
        int[][] r = new int[v.length / n][n];
        for (int i = 0; i < r.length; i++)
            for (int j = 0; j < n; j++) r[i][j] = v[i * n + j];
        return r;
    }
}
