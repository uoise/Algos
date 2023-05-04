class Solution {
    static int[] answer = {0, 0};

    public static void clc(final int[][] v, final int y, final int x, final int l) {
        final int tgt = v[y][x];
        boolean chk = true;
        for (int i = y; chk && i < y + l; i++)
            for (int j = x; chk && j < x + l; j++)
                if (tgt != v[i][j]) chk = false;

        if (chk) {
            answer[tgt]++;
            return;
        }
        int nl = l / 2;
        clc(v, y, x, nl);
        clc(v, y + nl, x, nl);
        clc(v, y, x + nl, nl);
        clc(v, y + nl, x + nl, nl);
    }

    public int[] solution(int[][] arr) {
        clc(arr, 0, 0, arr.length);
        return answer;
    }
}