import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static final int[] xx = {1, 0, -1, 0, 1, 1, -1, -1};
    static final int[] yy = {0, 1, 0, -1, 1, -1, 1, -1};
    static int[][] vv = new int[102][102];

    static boolean vld(final int[][] rv, final int y, final int x) {
        for (int[] v : rv)
            if ((v[1] < y && y < v[3]) && (v[0] < x && x < v[2])) return false;
        return true;
    }

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        for (int[] rv : rectangle) {
            for (int i = 0; i < 4; i++) rv[i] <<= 1;
            for (int y = rv[1]; y <= rv[3]; y++)
                for (int x = rv[0]; x <= rv[2]; x++)
                    vv[y][x] = -1;
        }

        vv[characterY <<= 1][characterX <<= 1] = 1;
        itemX <<= 1;
        itemY <<= 1;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{characterY, characterX, vv[characterY][characterX]});
        while (!q.isEmpty()) {
            int cy = q.peek()[0];
            int cx = q.peek()[1];
            int cr = q.peek()[2];
            q.poll();
            if (cy == itemY && cx == itemX) return (cr - 1) >> 1;
            for (int d = 0; d < 4; d++) {
                int ny = cy + yy[d], nx = cx + xx[d];
                if (vv[ny][nx] != -1 || !vld(rectangle, ny, nx)) continue;
                vv[ny][nx] = cr + 1;
                q.add(new int[]{ny, nx, vv[ny][nx]});
            }
        }
        return -1;
    }
}