class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0, t;
        while(n >= a) {
            t = n / a * b;
            answer += t;
            n = n % a + t;
        }
        return answer;
    }
}