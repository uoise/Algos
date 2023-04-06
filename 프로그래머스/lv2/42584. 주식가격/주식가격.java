import java.util.*;

class Solution {
    class Tv {
        int t;
        int v;

        public Tv(int t, int v) {
            this.t = t;
            this.v = v;
        }
    }

    public int[] solution(int[] prices) {
        Deque<Tv> stk = new ArrayDeque<>();
        int[] answer = new int[prices.length];
        for (int t = 0; t < prices.length; t++) {
            while (!stk.isEmpty() && stk.getLast().v > prices[t]) {
                answer[stk.getLast().t] = t - stk.getLast().t;
                stk.pollLast();
            }
            stk.add(new Tv(t, prices[t]));
        }
        while (!stk.isEmpty()) {
            answer[stk.getLast().t] = prices.length - 1 - stk.getLast().t;
            stk.pollLast();
        }
        return answer;
    }
}