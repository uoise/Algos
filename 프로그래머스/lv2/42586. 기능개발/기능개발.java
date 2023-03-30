import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public static final Queue<Integer> q = new ArrayDeque<>();

    public int[] solution(int[] progresses, int[] speeds) {
        int max = 0, cnt = 0;
        for (int i = 0; i < speeds.length; i++)
            speeds[i] = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] > 0 ? 1 : 0);
        for (int i : speeds) {
            if (max < i) {
                if (cnt > 0) q.add(cnt);
                cnt = 1;
                max = i;
            } else {
                ++cnt;
            }
        }
        q.add(cnt);
        return q.stream().mapToInt(i -> i).toArray();
    }
}