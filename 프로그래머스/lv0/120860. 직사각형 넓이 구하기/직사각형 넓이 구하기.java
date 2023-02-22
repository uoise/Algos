class Solution {
    public int solution(int[][] dots) {
        int x = dots[0][0], y = dots[0][1];
        boolean xc = false, yc = false;
        for (int i = 1; i < dots.length && (!xc || !yc); i++) {
            if (!xc && x != dots[i][0]) {
                x = Math.abs(x - dots[i][0]);
                xc = true;
            }
            if (!yc && y != dots[i][1]) {
                y = Math.abs(y - dots[i][1]);
                yc = true;
            }
        }
        return x * y;
    }
}