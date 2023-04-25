import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    static int fnd(int x, int[] arr) {
        if (arr[x] == x) return x;
        return arr[x] = fnd(arr[x], arr);
    }

    static boolean union(int x, int y, int[] arr) {
        x = fnd(x, arr);
        y = fnd(y, arr);
        if (x == y) return false;
        arr[y] = x;
        return true;
    }


    public int solution(int n, int[][] costs) {
        int answer = 0, cnt = n - 1;
        int[] group = new int[n];
        for (int i = 0; i < n; i++) group[i] = i;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[2]));
        for (int[] c : costs) pq.add(new int[]{Math.min(c[0], c[1]), Math.max(c[0], c[1]), c[2]});
        while (!pq.isEmpty() && cnt > 0) {
            int[] c = pq.poll();
            if (!union(c[0], c[1], group)) continue;
            answer += c[2];
            --cnt;
        }
        return answer;
    }
}