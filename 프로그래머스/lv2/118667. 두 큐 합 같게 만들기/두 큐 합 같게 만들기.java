class Solution {
    public int solution(int[] queue1, int[] queue2) {
        final int siz = queue1.length;
        int l = 1, r = siz;
        long[] sv = new long[siz * 2 + 1];
        sv[0] = 0;
        for (int i = 0; i < siz; i++) sv[i + 1] = sv[i] + queue1[i];
        for (int i = 0; i < siz; i++) sv[siz + 1 + i] = sv[siz + i] + queue2[i];
        long sum, tgt = sv[siz * 2] / 2;
        while (l <= r && r < siz * 2) {
            sum = sv[r] - sv[l - 1];
            if (sum == tgt) return r - siz + l - 1;
            if (sum < tgt) r++;
            else l++;
        }
        return -1;
    }
}