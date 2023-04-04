import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        String inp;
        String[] srr;
        Map<String, Integer> map = new HashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        inp = br.readLine();
        srr = inp.split(" ");
        int n = Integer.parseInt(srr[0]);
        int m = Integer.parseInt(srr[1]);
        for (int i = 0; i < n; i++) {
            inp = br.readLine();
            if (inp.length() < m) continue;
            map.put(inp, map.getOrDefault(inp, 0) + 1);
        }
        List<String> res = new ArrayList<>(map.keySet());
        res.sort((s1, s2) -> {
            int i1, i2;
            i1 = map.get(s1);
            i2 = map.get(s2);
            if (i1 != i2) return i2 - i1;
            if (s1.length() != s2.length()) return s2.length() - s1.length();
            return s1.compareTo(s2);
        });
        StringBuilder sb = new StringBuilder();
        for (String s : res) sb.append(s).append("\n");
        System.out.println(sb);
    }
}