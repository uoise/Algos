import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int[] solution(String s) {
        int[] pv = new int[26];
        Arrays.fill(pv, -1);
        return IntStream.range(0, s.length()).map(i -> {
            int idx = i;
            int pos = s.charAt(i) - 'a';
            i = pv[pos] == -1 ? -1 : i - pv[pos];
            pv[pos] = idx;
            return i;
        }).toArray();
    }
}