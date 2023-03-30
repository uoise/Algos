class Solution {
    public static int ly = 3, lx = 0, ry = 3, rx = 2, wl;

    boolean isLft(int ny, int nx) {
        if (nx != 1) return nx == 0;
        int ll = Math.abs(ly - ny) + Math.abs(lx - nx);
        int rl = Math.abs(ry - ny) + Math.abs(rx - nx);
        return ll == rl ? wl == 1 : ll < rl;
    }

    public String solution(int[] numbers, String hand) {
        StringBuilder answer = new StringBuilder();
        int ny, nx;
        wl = hand.equals("left") ? 1 : 0;
        for (int n : numbers) {
            if (n == 0) {
                ny = 3;
                nx = 1;
            } else {
                ny = (n - 1) / 3;
                nx = (n - 1) % 3;
            }

            if (isLft(ny, nx)) {
                answer.append("L");
                ly = ny;
                lx = nx;
            } else {
                answer.append("R");
                ry = ny;
                rx = nx;
            }
        }
        return answer.toString();
    }
}