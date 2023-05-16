import java.util.PriorityQueue;

class Solution {
    public int[] solution(int[] sequence, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (o1, o2) -> (o1[1] - o1[0] == o2[1] - o2[0] ? o1[0] - o2[0] : (o1[1] - o1[0]) - (o2[1] - o2[0]))
        );
        int[] sv = new int[sequence.length + 1];
        for (int i = 1; i < sv.length; i++) sv[i] = sv[i - 1] + sequence[i - 1];
        int ll = 1, rr = 1;

        while (ll < sv.length && rr < sv.length) {
            int sum = sv[rr] - sv[ll - 1];
            if (sum == k) pq.add(new int[]{ll - 1, rr - 1});
            if (sum > k || rr == sv.length - 1) ++ll;
            else ++rr;
        }

        return pq.peek();
    }
}