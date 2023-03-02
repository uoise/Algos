import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] numbers, String direction) {
        return Arrays.stream(IntStream.concat(Arrays.stream(numbers), Arrays.stream(numbers)).toArray(), direction.equals("left") ? 1 : numbers.length - 1, direction.equals("left") ? 1 + numbers.length : numbers.length * 2 - 1).toArray();
    }
}