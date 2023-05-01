import java.util.Arrays;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0, idx = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        for (int j : B) {
            if (A[idx] >= j) continue;
            idx++;
            answer++;
        }
        return answer;
    }
}