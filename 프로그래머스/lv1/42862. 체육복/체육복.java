import java.util.Arrays;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] arr = new int[n + 1];
        Arrays.fill(arr, 1);
        arr[0] = 0;
        for (int i : lost) --arr[i];
        for (int i : reserve) ++arr[i];
        for (int i = 1; i <= n; i++) {
            if (arr[i] > 1) {
                --arr[i];
                if (i > 1 && arr[i - 1] == 0) arr[i - 1] = 1;
                else if (i < n && arr[i + 1] == 0) arr[i + 1] = 1;
                else ++arr[i];
            }
        }
        return Arrays.stream(arr).map(i -> i > 0 ? 1 : 0).sum();
    }
}