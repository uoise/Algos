import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    private static final Map<String, Integer> mix = new HashMap<>();

    public static boolean clc(int[] tgt, int[] cur) {
        for (int i = 0; i < tgt.length; i++)
            if (tgt[i] != cur[i]) return false;
        return true;
    }

    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0, fnd;
        for (int i = 0; i < number.length; i++) mix.put(want[i], i);
        int[] cur = new int[mix.size()];
        Arrays.fill(cur, 0);

        for (int i = 0; i < discount.length; i++) {
            if (i > 9) {
                fnd = mix.getOrDefault(discount[i - 10], -1);
                if (fnd >= 0) --cur[fnd];
            }
            fnd = mix.getOrDefault(discount[i], -1);
            if (fnd >= 0) {
                ++cur[fnd];
                if (i > 8 && clc(number, cur)) ++answer;
            }
        }
        return answer;
    }
}