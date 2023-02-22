class Solution {
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int solution(int a, int b) {
        int answer = gcd(a, b);
        answer = b / answer;
        while (answer % 2 == 0) answer /= 2;
        while (answer % 5 == 0) answer /= 5;
        return answer == 1 ? 1 : 2;
    }
}