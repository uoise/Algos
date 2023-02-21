class Solution {
    public int solution(int[] common) {
        int i = 0, n = common.length;
        while (common[i] == 0 || common[i + 1] == 0) {
            i++;
            if (i == n - 2) return 0;
        }
        if (common[i + 1] % common[i] == 0 &&
                common[i + 2] % common[i + 1] == 0) 
            return common[n - 1] * common[i + 1] / common[i];
        return common[n - 1] + common[1] - common[0];
    }
}