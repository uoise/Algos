import java.util.Arrays;

class Solution {
    public static final int[] xx = {1, 0, -1, 0};
    public static final int[] yy = {0, 1, 0, -1};

    public int[] solution(String[] park, String[] routes) {
        boolean chk;
        int my = park.length, mx = park[0].length();
        int cy = 0, cx = 0, ny, nx, dr = 0, siz;
        int[][] vv = new int[my][mx];
        for (int[] v : vv) Arrays.fill(v, 0);
        for (int y = 0; y < my; y++) {
            for (int x = 0; x < mx; x++) {
                if (park[y].charAt(x) == 'X')
                    vv[y][x] = 1;
                else if (park[y].charAt(x) == 'S') {
                    cy = y;
                    cx = x;
                }
            }
        }
        for (String cmd : routes) {
            siz = Integer.parseInt(cmd.substring(2));
            switch (cmd.charAt(0)) {
                case 'E' -> dr = 0;
                case 'S' -> dr = 1;
                case 'W' -> dr = 2;
                case 'N' -> dr = 3;
            }
            chk = true;
            ny = cy;
            nx = cx;
            while (siz-- > 0 && chk) {
                ny += yy[dr];
                nx += xx[dr];
                if (ny < 0 || ny >= my || nx < 0 || nx >= mx || vv[ny][nx] == 1) chk = false;
            }
            if (chk) {
                cy = ny;
                cx = nx;
            }
        }
        return new int[]{cy, cx};
    }
}