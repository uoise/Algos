class Solution {

    static String clc(String s) {
        for (char c = 'A'; c <= 'G'; c++) s = s.replace(c + "#", String.valueOf(c).toLowerCase());
        return s;

    }

    static int tim(String s) {
        return Integer.parseInt(s.substring(0, 2)) * 60 + Integer.parseInt(s.substring(3));
    }


    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        int max = -1;
        m = clc(m);
        for (String s : musicinfos) {
            String[] d = s.split(",");
            d[3] = clc(d[3]);
            int len = tim(d[1]) - tim(d[0]);
            d[3] = d[3].repeat(len / d[3].length()) + d[3].substring(0, len % d[3].length());
            if (d[3].contains(m) && max < d[3].length()) {
                answer = d[2];
                max = d[3].length();
            }
        }
        return answer;
    }
}