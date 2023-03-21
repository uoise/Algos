import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int solution(int k, int m, int[] score) {
        Arrays.sort(score);
        return IntStream.range(0, score.length).filter(i -> i % m == m - 1).map(i -> score[score.length - 1 - i] * m).sum();
    }
}