import java.util.HashMap;
import java.util.Map;

class Solution {
    public static final Map<String, Integer> map = new HashMap<>();

    public int solution(String[][] clothes) {
        int answer = 1;
        for (String[] c : clothes) map.put(c[1], map.getOrDefault(c[1], 0) + 1);
        for (Map.Entry<String, Integer> e : map.entrySet()) answer *= e.getValue() + 1;
        return answer - 1;
    }
}