import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        int max = citations[citations.length - 1];
        while (max >= 0) {
            int cnt = 0, lft = 0;
            for (int i = 0; i < citations.length; i++) {
                if (citations[i] >= max) ++cnt;
                else ++lft;
            }
            if (cnt >= max && lft < max) return max;
            --max;
        }
        return 0;
    }
}