class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        final long R1 = (long) r1 * r1;
        final long R2 = (long) r2 * r2;
        for (long y = 1; y <= r2; y++) {
            long Y = y * y;
            long s = (long) Math.ceil(Math.sqrt(R1 - Y));
            long e = (long) Math.sqrt(R2 - Y);
            answer += (e - s + 1);
        }
        return answer << 2;
    }
}