class Solution {

    public int solution(String s) {
        char tgt = '!';
        int answer = 0, cnt = 0, cno = 0;
        for (int i = 0; i < s.length(); i++) {
            if (tgt == '!') tgt = s.charAt(i);
            if (s.charAt(i) == tgt) ++cnt;
            else ++cno;
            if (cnt == cno) {
                tgt = '!';
                cnt = 0;
                cno = 0;
                ++answer;
            }
        }
        return answer + (cnt + cno > 0 ? 1 : 0);
    }
}