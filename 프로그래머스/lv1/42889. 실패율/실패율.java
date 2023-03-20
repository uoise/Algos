import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[][] ar = new int[N + 1][3];
        for (int i = 0; i < ar.length; i++) {
            ar[i][0] = i;
            ar[0][1] = 0;
            ar[0][2] = 0;
        }
        for (int usr : stages) {
            for (int i = 0; i <= Math.min(usr, N); i++) {
                ar[i][1]++;
                ar[i][2]++;
            }
            if (usr <= N) ar[usr][1]--;
        }
        Arrays.sort(ar, Comparator.comparingDouble(x -> -1d * (x[2] - x[1]) / x[2]));
        return Arrays.stream(ar).mapToInt(v -> v[0]).filter(i -> i > 0).toArray();
    }
}
