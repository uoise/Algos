class Solution {
    public static final String[] ss = {"aya", "ye", "woo", "ma"};

    public int solution(String[] babbling) {
        int answer = 0;
        for (String b : babbling) {
            String t = b;
            boolean chk = true;
            int rct = -1;
            while (chk) {
                chk = false;
                for (int i = 0; i < 4 && !chk; i++) {
                    if (t.length() < ss[i].length() || rct == i) continue;
                    if (t.startsWith(ss[i])) {
                        rct = i;
                        chk = true;

                        if (t.length() == ss[i].length()) t = "";
                        else t = t.substring(ss[i].length());
                    }
                }
                if (chk && t.length() == 0) {
                    chk = false;
                    System.out.println(b);
                    ++answer;
                }
            }
        }
        return answer;
    }
}