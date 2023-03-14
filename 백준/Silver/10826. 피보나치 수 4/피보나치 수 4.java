import java.util.Scanner;

class Main {
    public static StringBuilder ret;
    public static int res;

    public static String add(String x, String y) {
        res = 0;
        ret = new StringBuilder();
        for (int i = 0; i < Math.max(x.length(), y.length()); i++) {
            if (i < x.length()) res += (x.charAt(x.length() - i - 1) - '0');
            if (i < y.length()) res += (y.charAt(y.length() - i - 1) - '0');
            ret.append(res % 10);
            res /= 10;
        }
        if (res > 0) ret.append(res);
        return ret.reverse().toString();
    }

    public static String sol() {
        int n = new Scanner(System.in).nextInt();
        if (n <= 1) return String.valueOf(n);
        String h = "0";
        String p = "1";
        String c = "";
        for (int i = 2; i <= n; i++) {
            c = add(h, p);
            h = p;
            p = c;
        }
        return c;
    }

    public static void main(String[] args) {
        System.out.print(sol());
    }
}