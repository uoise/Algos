import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    private static final Map<String, Integer> map = new HashMap<>();

    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        Arrays.fill(answer, 0);
        for (int i = 0; i < name.length; i++) map.put(name[i], yearning[i]);
        for (int i = 0; i < photo.length; i++) {
            for (String s : photo[i]) answer[i] += map.getOrDefault(s, 0);
        }
        return answer;
    }
}