import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] array) {
        return new int[]{Arrays.stream(array).max().orElse(0), Arrays.stream(array).boxed().collect(Collectors.toList()).indexOf(Arrays.stream(array).max().orElse(0))};
    }
}