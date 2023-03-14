class Solution {
    public static long[][] fv = {{1, 1}, {1, 0}};
    public static long[][] ev = {{1, 0}, {0, 1}};

    public static long[][] matMul(long[][] x, long[][] y) {
        long[][] ret = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret[i][k] = (ret[i][k] + x[i][j] * y[j][k]) % 1234567;
        return ret;
    }

    public int solution(int n) {
        n--;
        while (n > 0) {
            if (n % 2 == 1) ev = matMul(ev, fv);
            fv = matMul(fv, fv);
            n /= 2;
        }
        return (int) ev[0][0];
    }
}