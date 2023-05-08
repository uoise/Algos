import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static final int[] xx = {1, 0, -1, 0};
    static final int[] yy = {0, 1, 0, -1};
    static final int MD = 2;
    static final Queue<int[]> q = new LinkedList<>();
    static boolean[][] bv;
    static int SY, SX;

    boolean bfs(final String[] vv, int y, int x) {
        while (!q.isEmpty()) q.poll();
        bv[y][x] = true;
        int d = 0;
        q.add(new int[]{y, x, d});
        while (!q.isEmpty()) {
            y = q.peek()[0];
            x = q.peek()[1];
            d = q.peek()[2] + 1;
            q.poll();
            if (d > MD) continue;
            for (int i = 0; i < 4; i++) {
                int ny = y + yy[i], nx = x + xx[i];
                if (ny < 0 || ny >= SY || nx < 0 || nx >= SX || bv[ny][nx]) continue;
                if (vv[ny].charAt(nx) == 'X') continue;
                if (vv[ny].charAt(nx) == 'P') return false;
                bv[ny][nx] = true;
                q.add(new int[]{ny, nx, d});
            }
        }
        return true;
    }

    boolean sol(String[] vv) {
        SY = vv.length;
        SX = vv[0].length();
        bv = new boolean[SY][SX];
        for (int y = 0; y < SY; y++) {
            for (int x = 0; x < SX; x++) {
                if (bv[y][x] || vv[y].charAt(x) != 'P') continue;
                if (!bfs(vv, y, x)) return false;
            }
        }
        return true;
    }

    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        for (int i = 0; i < places.length; i++) answer[i] = sol(places[i]) ? 1 : 0;
        return answer;
    }
}