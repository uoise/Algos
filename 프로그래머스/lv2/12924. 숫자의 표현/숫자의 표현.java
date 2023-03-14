class Solution {
    public int solution(int n) {
        int answer = 1, sum;
        for (int i = 1; i < n; i++) {
            sum = 0;
            for (int j = i; j <= n && sum < n; j++) {
                sum += j;
                if (sum == n) {
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
}