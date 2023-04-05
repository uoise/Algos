import java.util.*;

class Solution {

    public int[] solution(String msg) {
        Queue<Integer> answer = new ArrayDeque<>();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < 26; i++) map.put(String.valueOf(Character.valueOf((char) ('A' + i))), i + 1);
        int idx = 0;
        while (idx < msg.length()) {
            int len = idx;
            int fnd = -1;
            while (fnd != 0 && len < msg.length()) {
                String tgt = msg.substring(idx, ++len);
                fnd = map.getOrDefault(tgt, 0);
                if (fnd == 0) {
                    map.put(tgt, map.size() + 1);
                    answer.add(map.get(msg.substring(idx, --len)));
                }
            }
            if (len == msg.length()) {
                answer.add(map.get(msg.substring(idx)));
            }
            idx = len;
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }
}