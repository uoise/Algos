import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0, cw = 0;
        Deque<int[]> dq = new LinkedList<>();
        for (int w : truck_weights) {
            while (!dq.isEmpty() && dq.peekFirst()[1] <= answer) cw -= dq.pollFirst()[0];
            while (dq.size() > bridge_length || cw + w > weight) {
                cw -= dq.peekFirst()[0];
                answer = dq.peekFirst()[1] - 1;
                dq.pollFirst();
            }
            cw += w;
            dq.addLast(new int[]{w, ++answer + bridge_length});
        }
        if (!dq.isEmpty()) answer = dq.peekLast()[1];
        return answer;
    }
}