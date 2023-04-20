import java.util.Arrays;

class Solution {
    public int solution(int m, int n, int[][] puddles) {
        final long div = 1000000007;
        long[][] dp = new long[m][n];
        for (long[] v : dp) Arrays.fill(v, 0L);
        for (int[] p : puddles) dp[p[0] - 1][p[1] - 1] = -1;
        for (int i = 0; i < m && dp[i][0] != -1; i++) dp[i][0] = 1;
        for (int i = 0; i < n && dp[0][i] != -1; i++) dp[0][i] = 1;
        for (int x = 1; x < m; x++) {
            for (int y = 1; y < n; y++) {
                if (dp[x][y] == -1) continue;
                dp[x][y] += dp[x][y - 1] != -1 ? dp[x][y - 1] : 0;
                dp[x][y] += dp[x - 1][y] != -1 ? dp[x - 1][y] : 0;
                dp[x][y] %= div;
            }
        }

        return (int) dp[m - 1][n - 1];
    }
}