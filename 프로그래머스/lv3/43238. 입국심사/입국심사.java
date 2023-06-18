import java.util.*;
import java.util.stream.*;

class Solution {
    public boolean sol(final long tim, final int n, final int[] v) {
        return IntStream.range(0, v.length)
            .mapToLong(i -> tim / v[i])
            .sum() >= n;
    }
    
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        long answer = (long) times[times.length - 1] * n;
        long s = 1, e = (long) times[times.length - 1] * n;
        while(s <= e) {
            long mid = (s + e) / 2;
            if (sol(mid, n, times)) {
                answer = Math.min(answer, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return answer;
    }
}