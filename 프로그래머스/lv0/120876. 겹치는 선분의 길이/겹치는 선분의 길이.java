class Solution {
    public int solution(int[][] lines) {
        int[] vv = new int[201];
        for (int i : vv) i = 0;
        int answer = 0;
        for (int i = 0; i < lines.length; i++)
            for (int j = lines[i][0]; j < lines[i][1]; j++) vv[j + 100]++;
        for (int i = 0; i < 201; i++)
            if (vv[i] > 1) answer++;
        return answer;
    }
}