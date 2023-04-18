import java.util.LinkedList;
import java.util.Queue;

class Solution {
    class Pi {
        int y, x;

        public Pi(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    private final int[] xx = {1, 0, -1, 0};
    private final int[] yy = {0, 1, 0, -1};

    public int solution(int[][] maps) {
        int ys = maps.length, xs = maps[0].length;
        Queue<Pi> q = new LinkedList<>();
        q.add(new Pi(0, 0));
        maps[0][0] = 2;
        while (!q.isEmpty()) {
            int y = q.peek().y, x = q.peek().x;
            q.poll();
            int ord = maps[y][x] + 1;
            for (int d = 0; d < 4; d++) {
                int ny = y + yy[d], nx = x + xx[d];
                if (ny < 0 || ny >= ys || nx < 0 || nx >= xs || maps[ny][nx] != 1) continue;
                maps[ny][nx] = ord;
                if ((ny == ys - 1) && (nx == xs - 1)) return maps[ny][nx] - 1;
                q.add(new Pi(ny, nx));
            }
        }
        return -1;
    }
}