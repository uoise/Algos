import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < s.length() && answer; i++)
            if (s.charAt(i) == '(') stk.push(1);
            else {
                if (stk.empty()) answer = false;
                else stk.pop();
            }

        return stk.size() == 0 && answer;
    }
}