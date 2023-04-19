import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static void rcr(Queue<int[]> q, int n, int src, int tmp, int dst) {
        if (n > 1) rcr(q, n - 1, src, dst, tmp);
        q.add(new int[]{src, dst});
        if (n > 1) rcr(q, n - 1, tmp, src, dst);
    }

    public int[][] solution(int n) {
        Queue<int[]> q = new LinkedList<>();
        rcr(q, n, 1, 2, 3);
        int i = 0;
        int[][] answer = new int[q.size()][];
        while (!q.isEmpty()) answer[i++] = q.poll();
        return answer;
    }
}