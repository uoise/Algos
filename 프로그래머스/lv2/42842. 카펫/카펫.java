class Solution {
    public static int MX = 2000003;

    public int[] solution(int brown, int yellow) {
        for (int i = 3; i <= MX; i++)
            for (int j = 3; j <= MX; j++) {
                if (((i - 2) * (j - 2) == yellow) && (i + j - 2 == brown / 2)) return new int[]{j, i};
                if (((i - 2) * (j - 2) > yellow) && (i + j - 2 > brown / 2)) break;
            }
        return new int[]{0, 0};
    }
}