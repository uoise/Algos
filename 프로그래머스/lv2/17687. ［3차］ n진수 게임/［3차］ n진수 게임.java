import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public String solution(int n, int t, int m, int p) {
        String tgt = IntStream.rangeClosed(0, t * m + p)
                .mapToObj(i -> Integer.toString(i, n))
                .collect(Collectors.joining());
        return IntStream.range(0, tgt.length())
                .filter(i -> i % m == p - 1)
                .mapToObj(tgt::charAt)
                .map(String::valueOf)
                .collect(Collectors.joining())
                .toUpperCase().substring(0, t);
    }
}