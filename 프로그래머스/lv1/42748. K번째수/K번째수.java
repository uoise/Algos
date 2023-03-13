import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        return Arrays.stream(commands).mapToInt(cmd -> IntStream.rangeClosed(cmd[0] - 1, cmd[1] - 1).map(i -> array[i]).sorted().boxed().collect(Collectors.toList()).get(cmd[2] - 1)).toArray();
    }
}