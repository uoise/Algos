class Solution {
    public int solution(int n) {
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            sb.append(n % 3);
            n /= 3;
        }
        for (int i = 0; i < sb.length(); i++) {
            n *= 3;
            n += sb.charAt(i) - '0';
        }
        return n;
    }
}