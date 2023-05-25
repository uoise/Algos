import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int x, int y, int n) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{y, 0});
        while (!q.isEmpty()) {
            y = q.peek()[0];
            int cur = q.peek()[1];
            if (y == x) return cur;
            q.poll();
            if (y % 3 == 0 && y / 3 >= x) q.add(new int[]{y / 3, cur + 1});
            if (y % 2 == 0 && y / 2 >= x) q.add(new int[]{y / 2, cur + 1});
            if (y - n >= x) q.add(new int[]{y - n, cur + 1});
        }
        return -1;
    }
}