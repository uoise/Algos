import java.util.Iterator;
import java.util.PriorityQueue;

class Solution {
    static class St implements Comparable<St> {
        public String s;
        public int t;

        public St(String s, int t) {
            this.s = s;
            this.t = t;
        }

        @Override
        public int compareTo(St o) {
            return t - o.t;
        }
    }

    static final PriorityQueue<St> pq = new PriorityQueue<>();

    public int solution(int cacheSize, String[] cities) {
        int answer = 0, tim = 0;
        for (String c : cities) {
            c = c.toLowerCase();
            Iterator<St> it = pq.iterator();
            if (pq.isEmpty()) {
                answer += 5;
            } else {
                boolean chk = false;
                while (it.hasNext()) {
                    St fnd = it.next();
                    if (fnd.s.equals(c)) {
                        ++answer;
                        pq.remove(fnd);
                        chk = true;
                        break;
                    }
                }
                if (!chk) answer += 5;
            }
            pq.add(new St(c, ++tim));
            if (pq.size() > cacheSize) pq.poll();
        }
        return answer;
    }
}
