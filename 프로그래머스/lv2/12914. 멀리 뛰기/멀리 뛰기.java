class Solution {
    public long solution(int n) {
        int[] dp = new int[n + 1];
        for (int i = 0; i < Math.min(3, n + 1); i++) dp[i] = i;
        for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
        return dp[n];
    }
}
