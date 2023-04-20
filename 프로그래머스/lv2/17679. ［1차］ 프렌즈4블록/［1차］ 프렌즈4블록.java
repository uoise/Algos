import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static final int[] xx = {1, 0, 1};
    static final int[] yy = {0, 1, 1};
    static final Queue<Character> q = new LinkedList<>();

    static void clc(StringBuilder[] vv, final int y, final int x, final int m, final int n) {
        char c = Character.toUpperCase(vv[y].charAt(x));
        if (!Character.isAlphabetic(c)) return;
        for (int d = 0; d < 3; d++) {
            int ny = y + yy[d], nx = x + xx[d];
            if (c != Character.toUpperCase(vv[ny].charAt(nx))) return;
        }
        c = Character.toLowerCase(c);
        for (int i = 0; i < 4; i++) vv[y + i / 2].setCharAt(x + i % 2, c);
    }

    static int sol(StringBuilder[] vv, final int m, final int n) {
        int cnt = 0;
        for (int y = 0; y < m - 1; y++)
            for (int x = 0; x < n - 1; x++)
                clc(vv, y, x, m, n);

        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (Character.isLowerCase(vv[y].charAt(x))) ++cnt;

        return cnt;
    }

    static void grv(StringBuilder[] vv, final int m, final int n) {
        for (int x = 0; x < n; x++) {
            for (int y = m - 1; y >= 0; y--)
                if (Character.isAlphabetic(vv[y].charAt(x)) && Character.isUpperCase(vv[y].charAt(x)))
                    q.add(vv[y].charAt(x));

            for (int y = m - 1; y >= 0; y--) vv[y].setCharAt(x, q.isEmpty() ? ' ' : q.poll());
        }
    }

    public int solution(int m, int n, String[] board) {
        int answer = 0;
        StringBuilder[] vv = new StringBuilder[m];
        for (int i = 0; i < m; i++) vv[i] = new StringBuilder(board[i]);
        while (true) {
            int res = sol(vv, m, n);
            if (res == 0) break;
            answer += res;
            grv(vv, m, n);
        }
        return answer;
    }
}