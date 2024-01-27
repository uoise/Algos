import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
	static final Deque<Integer> dq = new ArrayDeque<>();

	public int solution(int[] stones, int k) {
		int answer = Integer.MAX_VALUE;
		for (int i = 0; i < stones.length; i++) {
			if (!dq.isEmpty() && dq.peekFirst() == i - k) {
				dq.pollFirst();
			}
			while (!dq.isEmpty() && stones[i] >= stones[dq.peekLast()]) {
				dq.pollLast();
			}
			dq.addLast(i);
			if (i >= k - 1) {
				answer = Math.min(answer, stones[dq.peekFirst()]);
			}
		}
		return answer;
	}
}