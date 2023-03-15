import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] solution(int n, String[] words) {
        Set<String> set = new HashSet<>();
        char lst = 0;
        int ans = -1;
        for (int i = 0; i < words.length && ans < 0; i++) {
            if (i == 0) {
                set.add(words[i]);
            } else if (lst != words[i].charAt(0)) {
                ans = i;
            } else if (!set.add(words[i])) {
                ans = i;
            }
            lst = words[i].charAt(words[i].length() - 1);
        }
        return new int[]{ans < 0 ? 0 : ans % n + 1, ans < 0 ? 0 : ans / n + 1};
    }
}