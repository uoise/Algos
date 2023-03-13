import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);
        return IntStream.range(0, A.length).map(i -> A[i] * B[A.length - 1 - i]).sum();
    }
}