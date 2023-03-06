import java.util.Arrays;

class Solution {
    public int[] solution(int[] arr) {
        if (arr.length == 1) return new int[]{-1};
        int mn = Arrays.stream(arr).min().orElse(0);
        return Arrays.stream(arr).filter(i -> i != mn).toArray();
    }
}