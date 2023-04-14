import java.util.Arrays;

class Solution {
    public int[] solution(int n, int s) {
        if (n > s) return new int[]{-1};
        int[] answer = new int[n];
        Arrays.fill(answer, s / n);
        for (int i = 1; i <= s % n; i++) answer[n - i]++;
        return answer;
    }
}