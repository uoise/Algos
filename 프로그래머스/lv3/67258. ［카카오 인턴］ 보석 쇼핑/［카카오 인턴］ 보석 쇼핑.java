import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = {1, gems.length};
        final int tgt = (int) Arrays.stream(gems).distinct().count();
        int ll = 0, len = answer[1] - answer[0];
        Map<String, Integer> cnt = new HashMap<>();
        for (int rr = 0; rr < gems.length; rr++) {
            cnt.put(gems[rr], cnt.getOrDefault(gems[rr], 0) + 1);
            while (true) {
                final int fnd = cnt.getOrDefault(gems[ll], 0) - 1;
                if (fnd == 0) break;
                cnt.put(gems[ll++], fnd);
            }
            if (tgt == cnt.size() && len > rr - ll) {
                len = rr - ll;
                answer[0] = ll + 1;
                answer[1] = rr + 1;
            }
        }
        return answer;
    }
}