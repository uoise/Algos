import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static final int[] xx = {1, 0, -1, 0}, yy = {0, 1, 0, -1};
    static final Queue<int[]> q = new LinkedList<>();
    static int ys, xs;
    static boolean[][] bv;

    static int bfs(int y, int x, final String[] vv) {
        int ret = 0, ny, nx;
        q.add(new int[]{y, x});
        bv[y][x] = true;
        ret += vv[y].charAt(x) - '0';
        while (!q.isEmpty()) {
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();
            for (int d = 0; d < 4; d++) {
                ny = y + yy[d];
                nx = x + xx[d];
                if (ny < 0 || ny >= ys || nx < 0 || nx >= xs || vv[ny].charAt(nx) == 'X' || bv[ny][nx]) continue;
                ret += vv[ny].charAt(nx) - '0';
                bv[ny][nx] = true;
                q.add(new int[]{ny, nx});
            }
        }
        return ret;
    }

    public int[] solution(String[] maps) {
        Queue<Integer> answer = new LinkedList<>();
        ys = maps.length;
        xs = maps[0].length();
        bv = new boolean[ys][xs];
        for (int y = 0; y < ys; y++)
            for (int x = 0; x < xs; x++)
                if (maps[y].charAt(x) != 'X' && !bv[y][x]) answer.add(bfs(y, x, maps));
        if (answer.isEmpty()) return new int[]{-1};
        return answer.stream().mapToInt(i -> i).filter(i -> i > 0).sorted().toArray();
    }
}