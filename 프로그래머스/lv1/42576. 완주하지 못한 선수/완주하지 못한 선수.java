import java.util.HashMap;
import java.util.Map;

class Solution {
    public static final Map<String, Integer> set = new HashMap<>();

    public String solution(String[] participant, String[] completion) {
        for (String p : participant) set.put(p, set.getOrDefault(p, 0) + 1);
        for (String c : completion) {
            int fnd = set.get(c);
            if (--fnd > 0) set.put(c, fnd);
            else set.remove(c);
        }
        return set.keySet().stream().findFirst().orElse("");
    }
}