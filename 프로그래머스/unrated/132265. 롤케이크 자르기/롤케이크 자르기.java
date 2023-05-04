import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        Set<Integer> ls = new HashSet<>();
        Map<Integer, Integer> rm = new HashMap<>();
        for (int t : topping) rm.put(t, rm.getOrDefault(t, 0) + 1);
        for (int t : topping) {
            int cnt = rm.get(t);
            if (cnt == 1) rm.remove(t);
            else rm.put(t, cnt - 1);
            ls.add(t);
            if (ls.size() == rm.size()) ++answer;
        }
        return answer;
    }
}