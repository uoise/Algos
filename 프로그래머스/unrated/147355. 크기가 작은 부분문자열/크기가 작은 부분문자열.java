import java.util.stream.IntStream;

class Solution {
    public int solution(String t, String p) {
        return (int) IntStream.rangeClosed(0, t.length() - p.length()).
                map(i -> Long.parseLong(t.substring(i, i + p.length())) <= Long.parseLong(p) ? 1 : 0)
                .filter(i -> i > 0)
                .count();
    }
}