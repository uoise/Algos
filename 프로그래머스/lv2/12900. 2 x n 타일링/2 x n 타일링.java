class Solution {
    static final long MX = 1000000007L;

    static long[][] mul(long[][] x, long[][] y) {
        long[][] rv = new long[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    rv[i][k] = (rv[i][k] + x[i][j] * y[j][k]) % MX;
        return rv;
    }

    public int solution(int n) {
        if (n < 4) return n;
        long[][] a = {{1, 1}, {1, 0}};
        long[][] r = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n % 2 == 1) r = mul(r, a);
            a = mul(a, a);
            n >>= 1;
        }
        return (int) r[0][0];
    }
}