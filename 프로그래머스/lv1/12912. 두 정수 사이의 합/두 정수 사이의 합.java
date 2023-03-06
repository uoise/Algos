import java.util.stream.LongStream;

class Solution {
    public long solution(int a, int b) {
        return LongStream.range(Math.min(a, b), (Math.max(a, b)) + 1).sum();
    }
}