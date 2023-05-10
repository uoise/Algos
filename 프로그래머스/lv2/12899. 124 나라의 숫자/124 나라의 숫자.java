class Solution {
    public String solution(int n) {
        StringBuilder answer = new StringBuilder();
        while (n > 0) {
            int t = n % 3;
            if (t == 0) {
                answer.append(4);
                n = n / 3 - 1;
            } else {
                answer.append(t);
                n /= 3;
            }
        }
        return answer.reverse().toString();
    }
}
