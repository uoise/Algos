import java.util.Stack;

class Solution {
    public final static Stack<Character> stk = new Stack<>();
    public static int siz;
    public static int res;

    public int clc(String s) {
        res = 0;
        stk.clear();
        char c;
        for (int i = 0; i < siz; i++) {
            c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                if (stk.isEmpty()) ++res;
                stk.push((char) (c + (c == '(' ? 1 : 2)));
            } else {
                if (stk.isEmpty() || stk.peek() != c) return i;
                stk.pop();
            }
        }

        return stk.size() > 0 ? -2 : -1;
    }

    public int solution(String s) {
        int cnt = 0, pos;
        siz = s.length();
        while ((pos = clc(s)) >= 0) {
            s = s.substring(pos + 1) + s.substring(0, pos + 1);
            if (++cnt > siz) return 0;
        }
        return pos == -2 ? 0 : res;
    }
}