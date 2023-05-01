import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0, back = Integer.MIN_VALUE;
        Arrays.sort(routes, Comparator.comparingInt(o -> o[1]));
        for (int[] v : routes) {
            if (back >= v[0]) continue;
            back = v[1];
            ++answer;
        }
        return answer;
    }
}