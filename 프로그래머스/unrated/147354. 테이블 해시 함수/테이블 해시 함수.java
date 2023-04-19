import java.util.Arrays;

class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        final int c = col - 1;
        Arrays.sort(data, (o1, o2) -> o1[c] == o2[c] ? o2[0] - o1[0] : o1[c] - o2[c]);

        for (int i = row_begin - 1; i < row_end; i++) {
            int tmp = 0;
            for (int x : data[i]) tmp += x % (i + 1);
            if (i == row_begin - 1) answer = tmp;
            else answer ^= tmp;
        }
        return answer;
    }
}