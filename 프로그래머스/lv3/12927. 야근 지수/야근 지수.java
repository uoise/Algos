import java.util.PriorityQueue;

class Solution {
    public long solution(int n, int[] works) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int w : works) pq.add(-w);
        while (n-- > 0 && pq.peek() < 0) pq.add(1 + pq.poll());
        return pq.stream().mapToLong(i -> (long) i * i).sum();
    }
}