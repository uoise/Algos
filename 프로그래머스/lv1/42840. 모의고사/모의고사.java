import java.util.stream.IntStream;

class Solution {
    public static int[][] pv = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

    public int[] solution(int[] answers) {
        int max = -1;
        int[] answer = {0, 0, 0};
        for (int i = 0; i < answers.length; i++) {
            for (int j = 0; j < 3; j++) {
                if (answers[i] == pv[j][i % pv[j].length]) answer[j]++;
                max = Math.max(max, answer[j]);
            }
        }
        int finalMax = max;
        return IntStream.range(0, 3).filter(i -> answer[i] == finalMax).map(i -> ++i).toArray();
    }
}