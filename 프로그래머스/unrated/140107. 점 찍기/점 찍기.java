class Solution {
    public long solution(int k, int d) {
        long answer = 0;
        final long D = (long) d * d;
        for (long x = 0; x <= d; x += k)
            answer += (long) Math.sqrt(D - (x * x)) / k + 1;
        return answer;
    }
}