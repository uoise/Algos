import java.util.stream.LongStream;

class Solution {
    public int[] solution(int n, long left, long right) {
        return LongStream.rangeClosed(left, right).mapToInt(l -> (int) Math.max(l / n, l % n) + 1).toArray();
    }
}