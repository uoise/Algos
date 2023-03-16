import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int solution(int n) {
        boolean[] pr = new boolean[n + 1];
        Arrays.fill(pr, true);
        pr[0] = pr[1] = false;
        for (int i = 2; i <= n; i++)
            if (pr[i])
                for (int j = 2; i * j <= n; j++)
                    pr[i * j] = false;
        return (int) IntStream.rangeClosed(2, n).filter(i -> pr[i]).count();
    }
}