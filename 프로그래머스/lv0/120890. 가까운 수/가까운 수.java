import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int solution(int[] e, int n) {
        int[] tmp = IntStream.concat(Arrays.stream(e), IntStream.of(n)).sorted().toArray();
        for (int i = 0; i < tmp.length; i++)
            if (tmp[i] == n) {
                if (i == 0) return tmp[1];
                else if (i == tmp.length - 1)
                    return tmp[tmp.length - 2];
                else
                    return (tmp[i + 1] - n == n - tmp[i - 1]) ? tmp[i - 1] : (tmp[i + 1] - n > n - tmp[i - 1]) ? tmp[i - 1] : tmp[i + 1];
            }
        return -1;
    }
}