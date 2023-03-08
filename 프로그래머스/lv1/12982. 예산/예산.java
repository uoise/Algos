import java.util.Arrays;

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0, sum = 0;
        Arrays.sort(d);
        while (answer < d.length && sum + d[answer] <= budget) {
            sum += d[answer++];
        }
        return answer;
    }
}