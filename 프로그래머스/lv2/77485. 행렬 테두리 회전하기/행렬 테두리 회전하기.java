class Solution {
    int[][] vv;
    int[][] tv;

    void cpy(final int[][] src, int[][] dst) {
        for (int i = 0; i < src.length; i++)
            dst[i] = src[i].clone();
    }

    int rot(final int[] q) {
        final int dy = q[0] - 1, dx = q[1] - 1, uy = q[2] - 1, ux = q[3] - 1;
        int ret = Integer.MAX_VALUE;

        cpy(vv, tv);

        for (int x = dx; x < ux; x++) {
            tv[dy][x + 1] = vv[dy][x];
            ret = Math.min(ret, vv[dy][x]);
        }

        for (int y = dy; y < uy; y++) {
            tv[y + 1][ux] = vv[y][ux];
            ret = Math.min(ret, vv[y][ux]);
        }

        for (int x = ux; x > dx; x--) {
            tv[uy][x - 1] = vv[uy][x];
            ret = Math.min(ret, vv[uy][x]);
        }

        for (int y = uy; y > dy; y--) {
            tv[y - 1][dx] = vv[y][dx];
            ret = Math.min(ret, vv[y][dx]);
        }

        cpy(tv, vv);

        return ret;
    }

    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int idx = 0;
        vv = new int[rows][columns];
        tv = new int[rows][columns];
        for (int y = 0; y < vv.length; y++)
            for (int x = 0; x < vv[y].length; x++)
                vv[y][x] = y * vv[y].length + x + 1;
        for (int[] q : queries) answer[idx++] = rot(q);
        return answer;
    }
}