class Solution {
    public int solution(int M, int N) {
        if (N > M) {
            int t = M;
            M = N;
            N = t;
        }
        return (M - 1) + M * (N - 1);
    }
}