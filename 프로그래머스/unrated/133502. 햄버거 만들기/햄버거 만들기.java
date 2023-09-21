import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

class Solution {
	static Stack<Integer> stk = new Stack<>(); // main stack
	static Deque<Integer> ttk = new ArrayDeque<>(); // temporary stack

	private static final int[] bgr = {1, 3, 2, 1}; // burger recipe

	public int solution(int[] ingredient) {
		int answer = 0;
		for (int i : ingredient) {
			stk.add(i);
			if (stk.size() < 4 || stk.peek() != 1)
				continue;
			boolean isBurger = true;
			for (int j = 0; j < 4; j++) {
				if (stk.peek() != bgr[j]) {
					isBurger = false;
					break;
				}
				ttk.push(stk.pop());
			}
			if (!isBurger) {
				while (!ttk.isEmpty())
					stk.push(ttk.pollFirst());
			} else {
				while (!ttk.isEmpty())
					ttk.pollFirst();
				++answer;
			}
		}
		return answer;
	}
}