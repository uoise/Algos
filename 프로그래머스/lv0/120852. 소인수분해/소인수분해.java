import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int n) {
        List<Integer> arr = new ArrayList<>();
        boolean[] pr = new boolean[n + 1];
        for (int i = 0; i <= n; i++) pr[i] = true;
        for (int i = 2; i <= n; i++)
            if (pr[i])
                for (int j = 2; i * j <= n; j++) pr[i * j] = false;
        int t = n;
        for (int i = 2; i <= n; i++) {
            if (!pr[i]) continue;
            if (t % i == 0) arr.add(i);
            while (t % i == 0) t /= i;

        }
        return arr.stream().mapToInt(i -> i).toArray();
    }
}