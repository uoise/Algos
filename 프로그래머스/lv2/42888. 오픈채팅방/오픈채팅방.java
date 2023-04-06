import java.util.*;

class Solution {
    class Sb {
        String s;
        boolean b;

        public Sb(String s, boolean b) {
            this.s = s;
            this.b = b;
        }
    }

    public String[] solution(String[] record) {
        Map<String, String> map = new HashMap<>();
        Queue<Sb> q = new LinkedList<>();
        StringTokenizer st;
        for (String s : record) {
            st = new StringTokenizer(s);
            String op = st.nextToken();
            String uid = st.nextToken();
            if (st.hasMoreTokens()) {
                map.put(uid, st.nextToken());
                if (op.equals("Enter")) {
                    q.add(new Sb(uid, true));
                }
            } else {
                q.add(new Sb(uid, false));
            }
        }
        String[] answer = new String[q.size()];
        for (int i = 0; i < answer.length; i++) {
            Sb cur = q.poll();
            answer[i] = String.format("%s%s", map.get(cur.s), (cur.b ? "님이 들어왔습니다." : "님이 나갔습니다."));
        }
        return answer;
    }
}