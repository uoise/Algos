import java.util.HashSet;
import java.util.Set;

class Solution {
    class Pi {
        long y, x;

        public Pi(long y, long x) {
            this.y = y;
            this.x = x;
        }
    }

    public String[] solution(int[][] line) {
        Set<Pi> set = new HashSet<>();

        long dy = Long.MAX_VALUE, dx = Long.MAX_VALUE, uy = Long.MIN_VALUE, ux = Long.MIN_VALUE;
        for (int i = 0; i < line.length; i++) {
            long a = line[i][0], b = line[i][1], e = line[i][2];
            for (int j = i + 1; j < line.length; j++) {
                long c = line[j][0], d = line[j][1], f = line[j][2];
                long rd = (a * d) - (b * c);
                if (rd == 0) continue;

                long rx = (b * f) - (e * d);
                if (rx % rd != 0) continue;
                rx /= rd;

                long ry = (e * c) - (a * f);
                if (ry % rd != 0) continue;
                ry /= rd;
                set.add(new Pi((int) ry, (int) rx));
            }
        }
        for (Pi c : set) {
            dy = Math.min(dy, c.y);
            dx = Math.min(dx, c.x);
            uy = Math.max(uy, c.y);
            ux = Math.max(ux, c.x);
        }

        StringBuilder[] tmp = new StringBuilder[(int) (uy - dy + 1)];
        for (int i = 0; i < tmp.length; i++) tmp[i] = new StringBuilder(".".repeat((int) (ux - dx + 1)));
        for (Pi c : set) tmp[(int) (uy - c.y)].setCharAt((int) (c.x - dx), '*');

        String[] answer = new String[tmp.length];
        for (int i = 0; i < answer.length; i++) answer[i] = tmp[i].toString();
        return answer;
    }
}
