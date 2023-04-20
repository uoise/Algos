import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int[] solution(int n) {
        Queue<Integer> answer = new LinkedList<>();
        while (n > 1) {
            answer.add(n);
            if (n % 2 == 0) n >>= 1;
            else n = n * 3 + 1;
        }
        answer.add(1);
        return answer.stream().mapToInt(i -> i).toArray();
    }
}