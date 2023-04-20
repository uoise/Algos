class Solution {
    static StringBuilder rvr(StringBuilder s, int l, int r) {
        StringBuilder t = new StringBuilder(s.substring(l, r + 1));
        t.reverse();
        s.replace(l, r + 1, t.toString());
        return s;
    }

    public String solution(String my_string, int[][] queries) {
        StringBuilder answer = new StringBuilder(my_string);
        for (int[] q : queries) answer = rvr(answer, q[0], q[1]);
        return answer.toString();
    }
}