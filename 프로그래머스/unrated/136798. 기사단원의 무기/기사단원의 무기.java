class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0, cnt;
        for (int n = 1; n <= number; n++) {
            cnt = 0;
            for (int i = 1; i * i <= n && cnt <= limit; i++) {
                if (i * i == n) cnt++;
                else if (n % i == 0) cnt += 2;
            }
            answer += cnt > limit ? power : cnt;
        }
        return answer;
    }
}