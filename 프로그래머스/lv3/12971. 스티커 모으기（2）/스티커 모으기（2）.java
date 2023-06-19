class Solution {
    public int solution(int sticker[]) {
        if(sticker.length == 1) return sticker[0];
        int[][] dp = new int[sticker.length][2];
        dp[0][0] = dp[1][0] = sticker[0];
        dp[1][1] = sticker[1]; 
        dp[0][1] = 0;
        for(int j = 0; j < 2; j++)
            for (int i = 2; i < sticker.length; i++) 
                dp[i][j] = Math.max(dp[i - 2][j] + sticker[i], dp[i - 1][j]);
        
        return Math.max(dp[dp.length - 2][0], dp[dp.length - 1][1]);
    }
}