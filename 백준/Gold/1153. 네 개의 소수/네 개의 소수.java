import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n < 8) {
            System.out.println(-1);
            return;
        }
        boolean pr[] = new boolean[n + 1];
        Arrays.fill(pr, false);
        pr[0] = pr[1] = true;
        for (int i = 2; i <= n; i++)
            if (!pr[i])
                for (int j = 2; i * j <= n; j++) pr[i * j] = true;
        
        if (n % 2 == 0) {
            for (int i = 2; i <= n; i++)
                if (!pr[i] && !pr[n - 4 - i]) {
                    System.out.printf("2 2 %d %d", i, n - 4 - i);
                    return;
                }
        } else {
            for (int i = 2; i <= n; i++)
                if (!pr[i] && !pr[n - 5 - i]) {
                    System.out.printf("2 3 %d %d", i, n - 5 - i);
                    return;
                }
        }
    }
}

