import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cv = new int[n];
        int min = 50, idx = -1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            cv[i] = Integer.parseInt(st.nextToken());
            if (min >= cv[i]) {
                min = cv[i];
                idx = i;
            }
        }
        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (m >= min) {
            sb.append(idx);
            m -= min;
        }

        for (int i = 0; i < sb.length(); i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (cv[j] <= m + min) {
                    sb.setCharAt(i, (char) (j + '0'));
                    m += (min - cv[j]);
                    break;
                }
            }
            if (sb.charAt(0) == '0') {
                sb.delete(0, 1);
                i--;
                m += min;
            }
        }

        System.out.println(sb.isEmpty() || sb.charAt(0) == '0' ? '0' : sb);
    }
}