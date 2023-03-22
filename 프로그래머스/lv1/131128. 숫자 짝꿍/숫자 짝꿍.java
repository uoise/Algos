import java.util.Arrays;

class Solution {

    public String solution(String X, String Y) {
        int[] xc = new int[10];
        int[] yc = new int[10];
        Arrays.fill(xc, 0);
        Arrays.fill(yc, 0);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < X.length(); i++) ++xc[X.charAt(i) - '0'];
        for (int i = 0; i < Y.length(); i++) ++yc[Y.charAt(i) - '0'];
        for (int i = 9; i >= 0; i--) sb.append(String.valueOf(i).repeat(Math.min(xc[i], yc[i])));
        if (sb.length() > 1 && sb.charAt(0) == '0') return "0";
        return sb.length() == 0 ? "-1" : sb.toString();
    }
}