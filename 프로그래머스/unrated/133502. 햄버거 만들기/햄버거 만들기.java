import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;

class Solution {
    private static final Deque<Integer> stk = new ArrayDeque<>();
    private static final int[] bgr = {1, 3, 2, 1};

    public int solution(int[] ingredient) {
        int answer = 0;
        for (int i : ingredient) {
            stk.add(i);
            boolean chk = true;
            while (chk && stk.size() > 3 && stk.peekLast() == 1) {
                Iterator<Integer> it = stk.descendingIterator();
                for (int j = 0; j < 4 && it.hasNext() && chk; j++) if (it.next() != bgr[j]) chk = false;
                if (chk) {
                    for (int j = 0; j < 4; j++) stk.pollLast();
                    ++answer;
                }
            }
        }
        return answer;
    }
}
