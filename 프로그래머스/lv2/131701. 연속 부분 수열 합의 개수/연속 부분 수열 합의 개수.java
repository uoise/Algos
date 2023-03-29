import java.util.HashSet;
import java.util.Set;

class Solution {
    public static final Set<Integer> set = new HashSet<>();

    public int solution(int[] elements) {
        int n = elements.length;
        for (int i = 0; i < n; i++) {
            int sum = 0, cnt = 0, idx = i;
            while (cnt++ < n) {
                sum += elements[(idx++) % n];
                set.add(sum);
            }
        }
        return set.size();
    }
}