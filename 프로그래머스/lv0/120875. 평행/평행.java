class Solution {
    public int solution(int[][] dots) {
        int x, y;
        x = (dots[0][1] - dots[1][1]) * (dots[2][0] - dots[3][0]);
        y = (dots[2][1] - dots[3][1]) * (dots[0][0] - dots[1][0]);
        if (x == y) return 1;
        x = (dots[0][1] - dots[2][1]) * (dots[3][0] - dots[1][0]);
        y = (dots[3][1] - dots[1][1]) * (dots[0][0] - dots[2][0]);
        if (x == y) return 1;
        x = (dots[0][1] - dots[3][1]) * (dots[2][0] - dots[1][0]);
        y = (dots[2][1] - dots[1][1]) * (dots[0][0] - dots[3][0]);
        return x == y ? 1 : 0;
    }
}