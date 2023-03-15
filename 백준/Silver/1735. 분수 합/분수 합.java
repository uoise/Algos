import java.util.Scanner;

class Main {
    private final static Scanner sc;

    static {
        sc = new Scanner(System.in);
    }

    public static long gcd(long x, long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }


    public static void sol() {
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();
        long g = gcd(b, d);
        long l = b * d / g;
        long p = a * l / b + c * l / d;
        g = gcd(l, p);
        System.out.println(p / g + " " + l / g);
    }

    public static void main(String[] args) {
        sol();
    }
}