import java.util.Arrays;

class Solution {
    public int solution(int[][] triangle) {
        for (int i = 1; i < triangle.length; i++) {
            for (int j = 0; j < triangle[i].length; j++) {
                triangle[i][j] += Math.max(
                        j - 1 >= 0 ? triangle[i - 1][j - 1] : 0,
                        j < triangle[i - 1].length ? triangle[i - 1][j] : 0
                );
            }
        }
        return Arrays.stream(triangle[triangle.length - 1]).max().orElse(0);
    }
}