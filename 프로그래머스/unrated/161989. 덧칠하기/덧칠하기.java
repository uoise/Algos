class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0, utl = -1;
        for (int i = 0; i < section.length; i++) {
            if (utl < 0 || utl < section[i]) {
                utl = section[i] + m - 1;
                ++answer;
            }
        }
        return answer;
    }
}