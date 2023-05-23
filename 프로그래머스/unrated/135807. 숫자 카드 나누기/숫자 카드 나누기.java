class Solution {
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    int clc(int[] src, int[] tgt) {
        int ret = src[0];
        for (int i = 1; i < src.length; i++) ret = gcd(ret, src[i]);
        if (ret == 1) return 0;
        for (int i : tgt) if (i % ret == 0) return 0;
        return ret;
    }

    public int solution(int[] arrayA, int[] arrayB) {
        return Math.max(clc(arrayA, arrayB), clc(arrayB, arrayA));
    }
}