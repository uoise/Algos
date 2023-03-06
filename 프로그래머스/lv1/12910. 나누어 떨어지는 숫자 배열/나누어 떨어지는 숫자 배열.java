import java.util.Arrays;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        return Arrays.stream(arr).filter(i -> i % divisor == 0).count() == 0
                ? new int[]{-1}
                : Arrays.stream(arr).filter(i -> i % divisor == 0).sorted().toArray();
    }
}