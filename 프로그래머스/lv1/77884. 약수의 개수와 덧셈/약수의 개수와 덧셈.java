import java.util.stream.IntStream;

class Solution {
    public int solution(int left, int right) {
        return IntStream.range(left, right + 1)
                .map(i -> i * (IntStream.range(1, i + 1).filter(j -> i % j == 0).count() % 2 == 0 ? 1 : -1))
                .sum();
    }
}