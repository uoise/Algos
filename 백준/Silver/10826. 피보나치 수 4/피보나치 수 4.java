import java.math.BigInteger;
import java.util.Scanner;

class Main {
    public static String sol() {
        int n = new Scanner(System.in).nextInt();
        if (n < 2) return String.valueOf(n);
        BigInteger[] dp = new BigInteger[n + 1];
        dp[0] = BigInteger.ZERO;
        dp[1] = BigInteger.ONE;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1].add(dp[i - 2]);
        return dp[n].toString();
    }

    public static void main(String[] args) {
        System.out.print(sol());
    }
}
