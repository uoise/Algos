import java.util.PriorityQueue;

class Solution {
    public static final PriorityQueue<Integer> pq = new PriorityQueue<>();

    public int solution(int[] scoville, int K) {
        int answer = 0;
        for (int s : scoville) pq.add(s);
        while (pq.size() > 0) {
            int sum = pq.poll();
            if (sum >= K) return answer;
            if (pq.isEmpty()) return -1;
            ++answer;
            sum += pq.poll() * 2;
            pq.add(sum);
        }
        return -1;
    }
}