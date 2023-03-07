class Solution {
    public static int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    public int[] solution(int n, int m) {
        return new int[]{gcd(n, m), n * m / gcd(n, m)};
    }
}