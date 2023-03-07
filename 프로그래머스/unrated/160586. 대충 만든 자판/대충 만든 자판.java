import java.util.Arrays;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] dp = new int[26];
        Arrays.fill(dp, 102);
        int[] answer = new int[targets.length];
        Arrays.fill(answer, 0);

        for (String key : keymap)
            for (int i = 0; i < key.length(); i++)
                dp[key.charAt(i) - 'A'] = Math.min(dp[key.charAt(i) - 'A'], i + 1);

        for (int i = 0; i < targets.length; i++)
            for (int j = 0; j < targets[i].length(); j++) {
                if (dp[targets[i].charAt(j) - 'A'] == 102) {
                    answer[i] = -1;
                    break;
                }
                answer[i] += dp[targets[i].charAt(j) - 'A'];
            }

        return answer;
    }
}