import java.util.Arrays;

class Solution {
    public int solution(int n) {
        boolean[] pr = new boolean[n + 1];
        int ans = 0;
        Arrays.fill(pr, true);
        for (int i = 2; i <= n; i++)
            if (pr[i])
                for (int j = 2; i * j <= n; j++) pr[i * j] = false;
        for (int i = 1; i <= n; i++) if (!pr[i]) ++ans;
        return ans;
    }
}