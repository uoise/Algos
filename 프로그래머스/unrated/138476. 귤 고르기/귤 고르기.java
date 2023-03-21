import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public class Cv implements Comparable<Cv> {
        public int cnt;
        public int val;

        public Cv(int c, int v) {
            this.cnt = c;
            this.val = v;
        }

        @Override
        public int compareTo(Cv o) {
            return cnt < o.cnt ? 1 : -1;
        }
    }

    public static final Map<Integer, Integer> map = new HashMap<>();
    public static final PriorityQueue<Cv> pq = new PriorityQueue<>();

    public int solution(int k, int[] tangerine) {
        int answer = 0, sum = 0;
        for (int t : tangerine) {
            Integer fnd = map.get(t);
            if (fnd == null) map.put(t, 1);
            else map.replace(t, fnd + 1);
        }
        for (Map.Entry<Integer, Integer> el : map.entrySet()) pq.add(new Cv(el.getValue(), el.getKey()));

        while (sum < k) {
            sum += pq.poll().cnt;
            ++answer;
        }
        return answer;
    }
}