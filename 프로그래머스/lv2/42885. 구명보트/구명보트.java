import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Deque<Integer> q = Arrays.stream(people).sorted().boxed().collect(Collectors.toCollection(ArrayDeque::new));
        while (q.size() > 1) {
            if (q.getFirst() + q.getLast() <= limit) q.removeFirst();
            q.removeLast();
            ++answer;
        }
        return q.size() == 1 ? answer + 1 : answer;
    }
}